#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    a--, b--, c--;
    vector<int> w(m);
    vector<long long> sum(m + 1);
    for (int i = 0; i < m; i++) {
      cin >> w[i];
    }
    sort(w.begin(), w.end());
    for (int i = 1; i <= m; i++) {
      sum[i] = sum[i - 1] + w[i - 1];
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v), g[v].push_back(u);
    }
    auto bfs = [&](int s) -> vector<int> {
      vector<int> d(n);
      vector<int> visited(n);
      queue<int> q;
      visited[s] = 1;
      q.push(s);
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
          if (!visited[v]) {
            visited[v] = 1;
            d[v] = d[u] + 1;
            q.push(v);
          }
        }
      }
      return d;
    };
    vector<int> da = bfs(a);
    vector<int> db = bfs(b);
    vector<int> dc = bfs(c);
    long long ans = 1e18;
    for (int i = 0; i < n; i++) {
      if (da[i] + db[i] + dc[i] > m) {
        continue;
      }
      // cout << i << ' ' << db[i] << ' ' << da[i] + dc[i] + db[i] << ' ' << sum[db[i]] + sum[da[i] + dc[i] + db[i]] << '\n';
      ans = min(ans, sum[db[i]] + sum[da[i] + dc[i] + db[i]]);
    }
    cout << ans << '\n';
  }
}
