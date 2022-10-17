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

const int INF = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, B;
  cin >> N >> B;
  vector<int> c(N + 1), d(N + 1), p(N + 1), sz(N + 1);
  vector<vector<int>> a(N + 1);
  cin >> c[1] >> d[1];
  for (int i = 2; i <= N; i++) {
    cin >> c[i] >> d[i] >> p[i];
    a[p[i]].push_back(i);
  }
  vector<vector<array<int, 2>>> f(5001, vector<array<int, 2>>(5001, {INF, INF}));
  for (int i = 1; i <= N; i++) {
    f[i][0][0] = 0;
    f[i][0][1] = 0;
  }

  auto dfs = yc([&](auto _dfs, int u, int l) -> void {
    sz[u] = 1;
    f[u][1][0] = c[u];
    f[u][1][1] = c[u] - d[u];
    for (int v : a[u]) {
      if (v != l) {
        _dfs(v, u);
        for (int i = sz[u]; i >= 0; i--) {
          for (int j = 0; j <= sz[v]; j++) {
            f[u][i + j][0] = min(f[u][i + j][0], f[u][i][0] + f[v][j][0]);
            if (i != 0) {
              if (j != 0) {
                f[u][i + j][1] = min(f[u][i + j][1], f[u][i][1] + f[v][j][1]);
              }
              f[u][i + j][1] = min(f[u][i + j][1], f[u][i][1] + f[v][j][0]);
            }
          }
        }
        sz[u] += sz[v];
      }
    }
  });
  dfs(1, 1);
  for (int i = N; i >= 0; i--) {
    if (min(f[1][i][1], f[1][i][0]) <= B) {
      cout << i << '\n';
      return 0;
    }
  }
}
