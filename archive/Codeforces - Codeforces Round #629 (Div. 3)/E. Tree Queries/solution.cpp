#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<int>> t(n, vector<int>());
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    t[u].push_back(v);
    t[v].push_back(u);
  }
  vector<int> p(n), d(n), f(n), lvl(n);
  int cnt = 0;
  function<void(int, int)> dfs = [&](int u, int l) -> void {
    d[u] = cnt++;
    for (int v : t[u]) {
      if (v != l) {
        p[v] = u;
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
      }
    }
    f[u] = cnt++;
  };
  dfs(0, -1);
  while (m--) {
    int k;
    cin >> k;
    vector<int> v(k);
    for (int i = 0; i < k; i++) {
      cin >> v[i];
      v[i]--;
    }
    auto solve = [&]() -> void {
      sort(v.begin(), v.end(), [&](int e1, int e2) {
        return lvl[e1] < lvl[e2];
      });
      int cur = 0;
      for (int x : v) {
        if (d[cur] <= d[p[x]] && f[p[x]] <= f[cur]) {
          cur = p[x];
        } else {
          cout << "NO\n";
          return;
        }
      }
      cout << "YES\n";
    };
    solve();
  }
}
