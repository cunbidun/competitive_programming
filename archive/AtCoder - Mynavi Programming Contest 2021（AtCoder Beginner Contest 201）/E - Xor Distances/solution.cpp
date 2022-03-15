#include <bits/stdc++.h>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
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
  int MOD = 1e9 + 7;
  int N;
  cin >> N;
  vector<vector<array<long, 2>>> a(N);
  for (int i = 0; i < N - 1; i++) {
    long long u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }

  vector<int> sz(N);
  yc([&](auto _dfs, int u, int l) -> int {
    sz[u] = 1;
    for (auto [v, w] : a[u]) {
      if (v != l) {
        sz[u] += _dfs(v, u);
      }
    }
    return sz[u];
  })(0, 0);

  int ans = 0;
  auto dfs = yc([&](auto _dfs, int u, int l, int c) -> int {
    long long tot = 0;
    int cur_odd = 0;
    int cur_even = 0;
    int long tot_odd = 0;
    for (auto [v, w] : a[u]) {
      if (v != l) {
        int n = _dfs(v, u, c);
        if ((w >> c) & 1) { // change
          tot_odd += sz[v] - n;
          tot += 1LL * n * cur_odd + 1LL * (sz[v] - n) * cur_even;
          cur_odd += (sz[v] - n);
          cur_even += n;
        } else {
          tot_odd += n;
          tot += 1LL * (sz[v] - n) * cur_odd + 1LL * n * cur_even;
          cur_even += (sz[v] - n);
          cur_odd += n;
        }
      }
    }
    ans = (ans + (((tot + tot_odd) % MOD) * ((1LL << c) % MOD)) % MOD) % MOD;
    return tot_odd;
  });

  for (int i = 0; i < 60; i++) {
    dfs(0, 0, i);
    // cout << ans << '\n';
  }
  cout << ans << '\n';
}
