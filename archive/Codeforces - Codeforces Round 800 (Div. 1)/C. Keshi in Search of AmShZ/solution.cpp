#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(N + 1);
  vector<int> neighbor_count(N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    a[v].push_back(u);
    neighbor_count[u]++;
  }
  vector<int> d(N + 1, 1e9);
  vector<int> visited_count(N + 1);
  priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> q;
  q.push({0, N});
  while (!q.empty()) {
    auto [du, u] = q.top();
    q.pop();
    if (du >= d[u]) {
      continue;
    }
    d[u] = du;
    for (int v : a[u]) {
      visited_count[v] += 1;
      int dv = d[u] + 1 + neighbor_count[v] - visited_count[v];
      q.push({dv, v});
    }
  }
  cout << d[1] << '\n';
}
