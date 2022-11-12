#include <array>
#include <functional>
#include <iostream>
#include <math.h>
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
  int N;
  cin >> N;
  vector<int> a(N), p(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    p[a[i]] = i;
  }
  vector<vector<int>> st(N, vector<int>(19, 1e9));
  for (int i = 0; i < N; i++) {
    st[i][0] = a[i];
  }
  for (int j = 1; j <= 18; j++) {
    for (int i = 0; i + (1 << (j - 1)) < N; i++) {
      st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
  }
  auto rmq = [&](int l, int r) -> int {
    int k = log2(r - l + 1);
    return min(st[l][k], st[r - (1 << k) + 1][k]);
  };
  long long ans = 0;
  yc([&](auto solve, int l, int r) -> void {
    if (l > r) {
      return;
    }
    int mn = rmq(l, r);
    int pos = p[mn];
    ans += 1LL * mn * (pos - l + 1) * (r - pos + 1);
    solve(l, pos - 1);
    solve(pos + 1, r);
  })(0, N - 1);
  cout << ans << '\n';
}
