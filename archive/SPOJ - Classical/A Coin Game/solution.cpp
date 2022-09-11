#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1), s(N + 1);
  vector<vector<array<int, 2>>> f(N + 1, vector<array<int, 2>>(N + 1, {-1, -1}));
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    s[i] = a[i] + s[i - 1];
  }
  auto solve = yc([&](auto _solve, int current, int pick) -> array<int, 2> {
    if (f[current][pick][0] != -1) {
      return f[current][pick];
    }
    int res = s[current] - s[current - pick];
    int mx = 0, pos = 0;
    if (pick > 1 && current < N) {
      auto [val, k] = _solve(current, pick - 1);
      if (current + k <= N && mx < _solve(current + k, k)[0]) {
        mx = _solve(current + k, k)[0];
        pos = k;
      }
    }
    if (current + pick * 2 - 1 <= N) {
      if (mx < _solve(current + pick * 2 - 1, pick * 2 - 1)[0]) {
        mx = _solve(current + pick * 2 - 1, pick * 2 - 1)[0];
        pos = pick * 2 - 1;
      }
    }
    if (current + pick * 2 <= N) {
      if (mx < _solve(current + pick * 2, pick * 2)[0]) {
        mx = _solve(current + pick * 2, pick * 2)[0];
        pos = pick * 2;
      }
    }
    return f[current][pick] = {s[N] - s[current] - mx + res, pos};
  });
  cout << max(solve(1, 1), solve(2, 2))[0] << '\n';
}
