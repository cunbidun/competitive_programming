#include <array>
#include <functional>
#include <iostream>
#include <vector>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    vector<int> lg(N + 1);
    lg[1] = 0;
    for (int i = 2; i <= N; i++) {
      lg[i] = lg[i / 2] + 1;
    }

    vector<vector<array<int, 2>>> mn(N, vector<array<int, 2>>(19));
    vector<vector<array<int, 2>>> mx(N, vector<array<int, 2>>(19));
    for (int i = 0; i < N; i++) {
      mn[i][0] = {a[i], i};
      mx[i][0] = {a[i], i};
    }

    for (int j = 1; j < 19; j++) {
      for (int i = 0; i + (1 << j) <= N; i++) {
        mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
        mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
      }
    }
    auto get_mn = [&](int L, int R) -> array<int, 2> {
      int j = lg[R - L + 1];
      return min(mn[L][j], mn[R - (1 << j) + 1][j]);
    };
    auto get_mx = [&](int L, int R) -> array<int, 2> {
      int j = lg[R - L + 1];
      return max(mx[L][j], mx[R - (1 << j) + 1][j]);
    };
    auto cal = yc([&](auto solve, int l, int r) -> int {
      if (l == r) {
        return 0;
      }
      auto p1 = get_mn(l, r);
      auto p2 = get_mx(l, r);

      if (p1[1] > p2[1]) {
        swap(p1, p2);
      }
      return solve(l, p1[1]) + solve(p2[1], r) + 1;
    });

    cout << cal(0, N - 1) << '\n';
  }
}
