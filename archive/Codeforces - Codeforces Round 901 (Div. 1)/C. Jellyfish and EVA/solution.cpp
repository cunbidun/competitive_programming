#include <bits/stdc++.h>

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
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> c(N + 1);
    std::cout << std::fixed << setprecision(13);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      c[u].push_back(v);
    }
    vector<double> f(N + 1);
    vector<int> visisted(N + 1);
    vector<int> l;
    vector<vector<double>> remain(N + 1, vector<double>(N + 1));
    remain[0][0] = 1.0;

    for (int i = 2; i <= N; i += 2) {
      remain[i][0] = remain[i - 2][0] * (i - 1) / i;
      remain[i][i] = 1.0 / i;
      int count = 0;
      for (int j = i - 1; j >= 2; j--) {
        remain[i][j] = (remain[i - 2][j] * (count) + remain[i - 2][j - 1] * (i - 2 - count)) / i;
        count += 1;
      }
    }

    auto topological_sort = yc([&](auto dfs, int u) -> void {
      visisted[u] = 1;
      for (int v : c[u])
        if (!visisted[v]) {
          dfs(v);
        }
      l.push_back(u);
    });

    topological_sort(1);

    for (int u : l) {
      if (u == N) {
        f[u] = 1.0;
        continue;
      }
      int cu = c[u].size();
      if (cu % 2 == 1) {
        for (int v : c[u]) {
          f[u] += 1.0 / cu * f[v];
        }
      } else {
        vector<double> fv;
        for (int v : c[u]) {
          fv.push_back(f[v]);
        }
        sort(fv.begin(), fv.end());
        for (int i = 0; i < (int)fv.size(); i++) {
          f[u] += fv[i] * remain[cu][i + 1];
        }
      }
    }
    cout << f[1] << '\n';
  }
}
