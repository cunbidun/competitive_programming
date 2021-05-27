#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>());
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      a[u].push_back(v);
    }
    vector<int> d(n, 1e9);
    d[0] = 0;
    auto bfs = [&]() {
      queue<int> q;
      q.push(0);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u]) {
          if (d[v] == 1e9) {
            d[v] = d[u] + 1;
            q.push(v);
          }
        }
      }
    };
    bfs();
    vector<int> ans(n);
    vector<vector<int>> f(n, vector<int>(2, -1));
    function<int(int, int)> dfs = [&](int u, int c) {
      if (f[u][c] != -1) {
        return f[u][c];
      }
      f[u][c] = d[u];
      if (c == 1) {
        return f[u][c] = d[u];
      }
      for (int v : a[u]) {
        if (d[v] <= d[u]) {
          if (c == 0) {
            f[u][c] = min(f[u][c], dfs(v, 1));
          }
        } else {
          f[u][c] = min(f[u][c], dfs(v, c));
        }
      }
      return ans[u] = f[u][c];
    };
    dfs(0, 0);
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
