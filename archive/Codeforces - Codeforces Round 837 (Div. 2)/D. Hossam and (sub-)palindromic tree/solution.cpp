/**
 *  author: cunbidun
 *  created: Sunday, 2023-07-30 00:31:04 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vector<vector<int>> a(N);
    vector<vector<int>> closest(N, vector<int>(N));
    vector<vector<int>> f(N, vector<int>(N));
    vector<vector<int>> prev(N, vector<int>(N));
    vector<vector<int>> next(N, vector<int>(N, -1));
    vector<vector<array<int, 2>>> dis(N);
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u].push_back(v);
      a[v].push_back(u);
    }

    vector<vector<int>> local_closest(N, vector<int>(26, -1));

    auto dfs = yc([&](auto _dfs, int r, int d, int u, int l) -> void {
      if (u >= r) {
        dis[d].push_back({r, u});
      }
      for (int v : a[u]) {
        if (v != l) {
          for (int i = 0; i < 26; i++) {
            local_closest[v][i] = local_closest[u][i];
          }
          if (local_closest[v][S[v] - 'a'] == -1) {
            local_closest[v][S[v] - 'a'] = v;
          }
          prev[r][v] = u;
          next[r][v] = next[r][u];
          if (next[r][v] == -1) {
            next[r][v] = v;
          }
          _dfs(r, d + 1, v, u);
        }
      }
    });
    for (int i = 0; i < N; i++) {
      local_closest.assign(N, vector<int>(26, -1));
      local_closest[i][S[i] - 'a'] = i;
      dfs(i, 0, i, i);
      for (int j = 0; j < N; j++) {
        closest[i][j] = local_closest[j][S[j] - 'a'];
      }
    }

    int ans = 0;
    for (int d = 0; d < N; d++) {
      for (auto [u, v] : dis[d]) {
        if (d == 0) {
          f[u][v] = 1;
        } else {
          auto c = closest[u][v];
          if (c == v) {
            f[u][v] = f[u][prev[u][v]];

          } else {
            if (next[c][v] == v) {
              f[u][v] = max(f[u][prev[u][v]], 2);

            } else {
              f[u][v] = max(f[u][prev[u][v]], f[next[c][v]][prev[c][v]] + 2);
            }
          }
        }
        f[v][u] = f[u][v];
        ans = max(ans, f[u][v]);
      }
    }
    cout << ans << '\n';
  }
}
