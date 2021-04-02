#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> a(n, vector<int>());
  vector<int> p(k);
  for (int i = 0; i < k; i++) {
    cin >> p[i];
    p[i]--;
  }
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  auto bfs = [&](int s) {
    vector<int> d(n);
    vector<int> visited(n);
    visited[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : a[u]) {
        if (!visited[v]) {
          visited[v] = 1;
          d[v] = d[u] + 1;
          q.push(v);
        }
      }
    }
    return d;
  };
  vector<int> v0 = bfs(0);
  vector<int> v1 = bfs(n - 1);
  vector<pair<int, int>> l;
  for (int i : p) {
    l.push_back({v0[i], v1[i]});
  }
  sort(l.begin(), l.end(), [](auto p1, auto p2) {
    return p1.first - p1.second < p2.first - p2.second;
  });
  int mx = l[k - 1].second;
  int ans = 0;
  for (int i = k - 2; i >= 0; i--) {
    ans = max(ans, l[i].first + mx);
    mx = max(mx, l[i].second);
  }
  cout << min(v0[n - 1], ans + 1) << '\n';
}
