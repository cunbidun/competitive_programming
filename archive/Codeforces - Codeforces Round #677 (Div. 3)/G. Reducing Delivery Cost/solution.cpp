#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<array<int, 2>>> a(n, vector<array<int, 2>>());
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  vector<array<int, 3>> e;
  vector<array<int, 2>> q;
  auto dijkstra = [&](int s) {
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, s});
    d[s][s] = 0;
    while (!pq.empty()) {
      int u = pq.top()[1];
      int du = pq.top()[0];
      pq.pop();
      if (du > d[s][u]) {
        continue;
      }
      for (auto p : a[u]) {
        int v = p[1];
        int uv = p[0];
        if (d[s][u] + uv < d[s][v]) {
          d[s][v] = d[s][u] + uv;
          pq.push({d[s][v], v});
        }
      }
    }
  };

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    a[u].push_back({w, v});
    a[v].push_back({w, u});
    e.push_back({u, v, w});
  }
  for (int i = 0; i < n; i++) {
    dijkstra(i);
  }
  int ans = 0;
  for (int i = 0; i < k; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    ans += d[u][v];
    q.push_back({u, v});
  }

  for (int r = 0; r < m; r++) {
    int res = 0;
    int eu = e[r][0];
    int ev = e[r][1];
    for (auto [u, v] : q) {
      int mn = min(d[u][v], d[u][eu] + d[v][ev]);
      mn = min(mn, d[u][ev] + d[v][eu]);
      res += mn;
    }
    ans = min(ans, res);
  }
  cout << ans << '\n';
}
