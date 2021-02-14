#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n);
  vector<vector<int>> p(n);

  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a[u].push_back(v);
    p[v].push_back(u);
  }

  auto check = [&](pair<int, int> e) {
    int ok = 1;
    vector<int> visited(n);
    function<void(int)> dfs = [&](int u) {
      visited[u] = 1;
      for (int v : a[u]) {
        if (u != e.first || v != e.second) {
          if (visited[v] == 1) {
            ok = 0;
          }
          if (visited[v] == 0) {
            dfs(v);
          }
        }
      }
      visited[u] = 2;
    };
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    return ok;
  };

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j : p[i]) {
      ans |= check({j, i});
    }
  }
  if (ans) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
