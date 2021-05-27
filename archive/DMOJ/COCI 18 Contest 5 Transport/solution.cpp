#include <bits/stdc++.h>

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun>
decltype(auto) y_combinator(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

int main() {
  using namespace std;
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), sz(n), lvl(n);
  vector<bool> is_c(n);
  vector<vector<int>> c_tree(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<array<int, 2>>> T(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w, u--, v--;
    T[u].push_back({v, w}), T[v].push_back({u, w});
  }
  vector<vector<long long>> d(n);
  auto f = y_combinator([&](auto f, int r, int u, int l, long long c, long long mn) -> void {        
    d[r].push_back(mn);
    for (auto [v, w] : T[u]) {
      if (v != l && !is_c[v]) {
        long long minv = min(mn, c + a[u] - w);
        f(r, v, u, c + a[u] - w, minv);
      }
    }
  });
  long long ans = 0;
  y_combinator([&](auto build, int c_u, int c_l) -> int {
    auto cal_sub = y_combinator([&](auto dfs, int u, int l) -> int {
      sz[u] = 1;
      for (auto [v, w] : T[u]) {
        if (v != l && !is_c[v]) {
          sz[u] += dfs(v, u);
        }
      }
      return sz[u];
    });
    int n_node = cal_sub(c_u, c_l);
    auto find = y_combinator([&](auto dfs, int u, int l) -> int {
      for (auto [v, w] : T[u]) {
        if (v != l && sz[v] * 2 > n_node && !is_c[v]) {
          return dfs(v, u);
        }
      }
      return u;
    });
    int cur = find(c_u, c_l);
    is_c[cur] = 1;
    f(cur, cur, cur, 0, a[cur]);
    sort(d[cur].begin(), d[cur].end());
    for (long long j : d[cur]) {
      if (j >= 0) {
        ans++;
      }
    }
    for (auto [v, w] : T[cur]) {
      if (!is_c[v]) {
        f(v, v, cur, 0, a[v]);
        sort(d[v].begin(), d[v].end());
      }
    }
    for (int i = 0; i < (int)T[cur].size(); i++) {
      int c_v = T[cur][i][0], c_w = T[cur][i][1];
      if (!is_c[c_v]) {
        auto b = y_combinator([&](auto b, int r, int u, int l, long long c, long long mn) -> void {
          if (mn >= 0) {
            int cp = lower_bound(d[cur].begin(), d[cur].end(), -c) - d[cur].begin();
            cp = d[cur].size() - cp;
            int cc = 0;
            if (c + a[cur] >= c_w) {
              cc = lower_bound(d[c_v].begin(), d[c_v].end(), -(c + a[cur] - c_w)) - d[c_v].begin();
              cc = d[c_v].size() - cc;
            }
            ans += cp - cc;
          }
          for (auto [v, w] : T[u]) {
            if (v != l && !is_c[v]) {
              long long minv = min(1LL * a[v] - w, mn + a[v] - w);
              b(r, v, u, a[v] - w + c, minv);
            }
          }
        });
        b(c_v, c_v, cur, a[c_v] - c_w, a[c_v] - c_w);
      }
    }
    is_c[cur] = 1;
    for (auto [v, w] : T[cur]) {
      d[v].clear();
    }
    d[cur].clear();
    for (auto [v, w] : T[cur]) {
      if (!is_c[v]) {
        int nxt = build(v, cur);
        c_tree[cur].push_back(nxt);
      }
    }
    return cur;
  })(0, 0);
  cout << ans - n << '\n';
}
