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
  int MOD = 1e9 + 7;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";

    int N;
    cin >> N;

    vector<vector<array<int, 2>>> a(N + 1);
    vector<vector<int>> val(N + 1, vector<int>(21));

    for (int i = 1; i < N; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      a[u].push_back({v, w}), a[v].push_back({u, w});
    }

    long long tot = 0;
    yc([&](auto _dfs, int u, int l = -1) -> void {
      for (auto [v, w] : a[u]) {
        if (v != l) {
          _dfs(v, u);
          for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
              tot += 1LL * (val[u][i] + (i == w)) * (val[v][j] + (j == w)) *
                     min({i, j, w});
            }
          }
          for (int i = 20; i >= 1; i--) {
            if (i >= w) {
              val[u][w] += val[v][i];
            } else {
              val[u][i] += val[v][i];
            }
          }
          val[u][w]++;
        }
      }
    })(1);

    tot %= MOD;
    long long ans = 1;

    yc([&](auto _dfs, int u, int l = 1,
           vector<int> pval = vector<int>(21)) -> void {
      for (auto [v, w] : a[u]) {
        if (v != l) {
          for (int i = 20; i >= 1; i--) {
            if (i <= w) {
              pval[i] += val[v][i];
            } else {
              pval[w] += val[v][i];
            }
          }
          pval[w]++;
        }
      }

      for (auto [v, w] : a[u]) {
        if (v != l) {
          vector<int> tmp = pval;
          for (int i = 20; i >= 1; i--) {
            if (i >= w) {
              tmp[w] -= val[v][i];
            } else {
              tmp[i] -= val[v][i];
            }
          }
          tmp[w]--;

          long long res = 0;
          for (int i = 1; i <= 20; i++) {
            for (int j = 1; j <= 20; j++) {
              res += 1LL * (tmp[i] + (i == w)) * (val[v][j] + (j == w)) *
                     min({i, j, w});
            }
          }
          ans = (ans * ((tot - res) % MOD + MOD) % MOD) % MOD;

          for (int i = 20; i > w; i--) {
            tmp[w] += pval[i];
            tmp[i] = 0;
          }
          tmp[w]++;

          _dfs(v, u, tmp);
        }
      }
    })(1);

    cout << ans << '\n';
  }
}
