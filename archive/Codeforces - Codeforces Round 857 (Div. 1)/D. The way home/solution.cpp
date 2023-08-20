/**
 *  author: cunbidun
 *  created: Tuesday, 2023-07-25 20:55:06 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using ll = long long;
  ll INF = 1e18;
  int T;
  cin >> T;
  while (T--) {
    int N, M, P;
    cin >> N >> M >> P;
    vector<array<ll, 2>> w(N);
    for (int i = 0; i < N; i++) {
      cin >> w[i][0];
      w[i][1] = i;
    }
    w[N - 1][0] = 2e9;
    vector<vector<array<int, 2>>> g(N);
    for (int i = 0; i < M; i++) {
      int a, b, s;
      cin >> a >> b >> s;
      a--, b--;
      g[a].push_back({s, b});
    }
    vector<vector<ll>> d(N, vector<ll>(N, INF));
    auto dijkstra = [&](int s) {
      d[s][s] = 0;

      priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> pq;
      pq.push({0, s});

      while (!pq.empty()) {
        int u = pq.top()[1];
        long long du = pq.top()[0];
        pq.pop();
        if (du > d[s][u]) {
          continue;
        }
        for (auto p : g[u]) {
          int v = p[1];
          long long uv = p[0];
          if (d[s][u] + uv < d[s][v]) {
            d[s][v] = d[s][u] + uv;
            pq.push({d[s][v], v});
          }
        }
      }
    };
    for (int i = 0; i < N; i++) {
      dijkstra(i);
    }
    if (d[0][N - 1] == INF) {
      cout << -1 << '\n';
      continue;
    }
    vector<ll> f(N, INF);
    vector<ll> carry(N, 0);
    sort(w.begin(), w.end());
    int p = -1;
    for (int i = 0; i < N; i++) {
      if (w[i][1] == 0) {
        p = i;
        break;
      }
    }
    f[p] = 0;
    carry[p] = P;
    for (int i = p + 1; i < N; i++) {
      for (int j = p; j < i; j++) {
        if (d[w[j][1]][w[i][1]] == INF) {
          continue;
        }
        ll cost_need = max(d[w[j][1]][w[i][1]] - carry[j], 0LL);
        ll num_move = (cost_need + w[j][0] - 1) / w[j][0];
        if (f[i] > f[j] + num_move) {
          f[i] = f[j] + num_move;
          carry[i] = carry[j] + num_move * w[j][0] - d[w[j][1]][w[i][1]];
        } else if (f[i] == f[j] + num_move) {
          carry[i] = max(carry[i], carry[j] + num_move * w[j][0] - d[w[j][1]][w[i][1]]);
        }
      }
    }
    cout << f[N - 1] << '\n';
  }
}
