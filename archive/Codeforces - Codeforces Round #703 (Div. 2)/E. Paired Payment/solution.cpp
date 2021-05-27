#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<long long, int>>> a(n, vector<pair<long long, int>>());
  vector<vector<array<long long, 2>>> mn_cost(n, vector<array<long long, 2>>(51, {(int)1e9, (int)1e9}));
  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    a[u].push_back({w, v});
    a[v].push_back({w, u});
  }

  typedef pair<long long, array<long long, 3>> e;
  auto dijkstra = [&](int s) {
    priority_queue<e, vector<e>, greater<e>> pq;
    pq.push({0, {s, 0, 0}});
    mn_cost[0][0][0] = 0;
    while (!pq.empty()) {
      int u = pq.top().second[0];
      int odd = pq.top().second[1];
      long long l = pq.top().second[2];
      long long du = pq.top().first;
      pq.pop();
      if (du > mn_cost[u][l][odd]) {
        continue;
      }
      for (auto p : a[u]) {
        int v = p.second;
        long long uv = p.first;
        long long c = 1e9;
        if (odd == 0) {
          c = du + uv * uv;
        } else {
          for (int i = 0; i <= 50; i++) {
            c = min(c, mn_cost[u][i][odd] + 2 * i * uv + uv * uv);
          }
        }
        if (mn_cost[v][uv][1 - odd] > c) {
          mn_cost[v][uv][1 - odd] = c;
          pq.push({c, {v, 1 - odd, uv}});
        }
      }
    }
  };
  dijkstra(0);
  for (int i = 0; i < n; i++) {
    long long mn = 1e9;
    for (int j = 0; j <= 50; j++) {
      mn = min(mn, mn_cost[i][j][0]);
    }
    if (mn == 1e9) {
      cout << -1 << ' ';
    } else {
      cout << mn << ' ';
    }
  }
  cout << '\n';
}
