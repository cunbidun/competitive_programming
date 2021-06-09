#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<array<int, 3>>> a(N, vector<array<int, 3>>());
  for (int i = 0; i < M; i++) {
    int A, B, C, D;
    cin >> A >> B >> C >> D;
    A--, B--;
    a[A].push_back({B, C, D}), a[B].push_back({A, C, D});
  }
  vector<long long> dis(N, 1e18);
  dis[0] = 0;
  typedef array<long long, 2> e;
  priority_queue<e, vector<e>, greater<e>> pq;
  pq.push({0, 0});
  while (!pq.empty()) {
    int u = pq.top()[1];
    long long du = pq.top()[0];
    pq.pop();
    if (du > dis[u]) {
      continue;
    }
    for (auto [v, c, d] : a[u]) {
      long long dv = 1e18;
      dv = min(dv, du + c + d / (du + 1));
      long long sqr = sqrt(d);
      for (long long t = max(0LL, sqr - 2); t <= sqr + 2; t++) {
        if (t >= du) {
          dv = min(dv, t + c + d / (t + 1));
        }
      }
      if (dv < dis[v]) {
        dis[v] = dv;
        pq.push({dis[v], v});
      }
    }
  }

  cout << ((dis[N - 1] == 1e18) ? -1 : dis[N - 1]) << '\n';
}
