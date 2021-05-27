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

  auto check = [&](pair<int, int> e, vector<vector<int>> &g) {
    int ok = 1;
    vector<int> visited(n);
    function<void(int)> dfs = [&](int u) {
      visited[u] = 1;
      for (int v : g[u]) {
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

  int ans = check({-1, -1}, a);

  vector<int> ch(n);
  for (int i = 0; i < n; i++) {
    int ok = 1;
    vector<int> visited(n);
    function<void(int)> dfs = [&](int u) {
      visited[u] = 1;
      for (int v : a[u]) {
        if (v == i) {
          ok = 0;
        }
        if (!visited[v]) {
          dfs(v);
        }
      }
      visited[u] = 2;
    };
    dfs(i);
    ch[i] = ok;
  }

  vector<vector<int>> n_a(n);
  vector<vector<int>> n_p(n);
  for (int i = 0; i < n; i++) {
    if (!ch[i]) {
      for (int j : a[i]) {
        if (!ch[j]) {
          n_a[i].push_back(j);
          n_p[j].push_back(i);
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if ((int)n_p[i].size() == 1) {
      ans |= check({n_p[i][0], i}, n_a);
    }
  }
  if (ans) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
