#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  int n1, n2, n3;
  cin >> n >> m >> n1 >> n2 >> n3;
  n1 += n3;
  vector<vector<int>> a(n);
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v), a[v].push_back(u);
  }
  vector<int> visited(n);
  int ok = 1;
  int cnt = 0;
  int tot = 0;
  function<void(int, int)> dfs = [&](int u, int c) {
    tot++;
    if (c == 1) {
      cnt++;
    }
    visited[u] = c;
    for (int v : a[u]) {
      if (!visited[v]) {
        dfs(v, 3 - c);
      } else if (visited[v] == visited[u]) {
        ok = 0;
      }
    }
  };
  vector<array<int, 3>> p;
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      ok = 1;
      cnt = 0;
      tot = 0;
      dfs(i, 1);
      if (!ok) {
        cout << "NO\n";
        return 0;
      }
      p.push_back({cnt, tot - cnt, i});
    }
  }
  vector<vector<int>> f(n + 1, vector<int>(n + 1));
  f[0][0] = 1;
  for (int i = 0; i < (int)p.size(); i++) {
    int s1 = p[i][0], s2 = p[i][1];
    for (int j = 0; j <= n; j++) {
      if (j >= s1) {
        f[i + 1][j] |= f[i][j - s1];
      }
      if (j >= s2) {
        f[i + 1][j] |= f[i][j - s2];
      }
    }
  }
  if (!f[p.size()][n2]) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  vector<int> c(n);
  for (int i = (int)p.size() - 1; i >= 0; i--) {
    if (n2 >= p[i][0] && f[i][n2 - p[i][0]]) {
      c[p[i][2]] = 2;
      n2 -= p[i][0];
    } else {
      c[p[i][2]] = 1;
      n2 -= p[i][1];
    }
  }
  visited.assign(n, 0);
  for (int i = 0; i < n; i++) {
    if (c[i] != 0) {
      dfs(i, c[i]);
    }
  }
  for (int i = 0; i < n; i++) {
    if (n3 == 0) {
      break;
    }
    if (visited[i] == 1) {
      visited[i] = 3;
      n3--;
    }
  }
  for (int i : visited) {
    cout << i;
  }
  cout << '\n';
}
