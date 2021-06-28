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
decltype(auto) yc(Fun &&fun) {
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
    int N, M;
    cin >> N >> M;
    vector<long long> a(N);
    vector<long long> b(N);
    for (long long &p : a) {
      cin >> p;
    }
    for (long long &p : b) {
      cin >> p;
    }
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    vector<int> visited(N), p(N);
    yc([&](auto dfs, int u) -> void {
      visited[u] = 1;
      for (int v : g[u]) {
        if (!visited[v]) {
          p[v] = u;
          dfs(v);
        }
      }
    })(0);
    vector<int> cnt(N);
    for (int i = 0; i < N; i++) {
      cnt[p[i]]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++) {
      if (cnt[i] == 0) {
        q.push(i);
      }
    }
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      a[p[u]] -= a[u];
      b[p[u]] -= b[u];
      cnt[p[u]]--;
      if (cnt[p[u]] == 0) {
        q.push(p[u]);
      }
    }
    if (a[0] == b[0]) {
      cout << "YES\n";
      continue;
    } else {
      vector<int> color(N);
      visited.assign(N, 0);
      color[0] = 1;
      int f = 0;
      yc([&](auto dfs, int u) -> void {
        visited[u] = 1;
        for (int v : g[u]) {
          if (!visited[v]) {
            color[v] = 3 - color[u];
            dfs(v);
          } else {
            if (color[v] != 3 - color[u]) {
              f = 1;
            }
          }
        }
      })(0);
      if (f && (a[0] - b[0]) % 2 == 0) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
  }
}
