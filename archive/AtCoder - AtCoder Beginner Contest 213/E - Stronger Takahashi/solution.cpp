#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W;
  cin >> H >> W;
  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  vector<vector<char>> a(H + 2, vector<char>(W + 2));
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      cin >> a[i][j];
    }
  }
  auto get = [&](int i, int j) -> int {
    return (i - 1) * W + j;
  };
  vector<vector<array<int, 2>>> g(505 * 505);
  for (int i = 1; i <= H; i++) {
    for (int j = 1; j <= W; j++) {
      for (int k = 0; k < 4; k++) {
        if (a[i + dx[k]][j + dy[k]] == '.') {
          g[get(i, j)].push_back({0, get(i + dx[k], j + dy[k])});
        }
      }
      for (int k = max(1, i - 5); k <= min(H, i + 5); k++) {
        for (int l = max(1, j - 5); l <= min(W, j + 5); l++) {
          if (abs(i - k) == 2 && abs(j - l) == 2) {
            if (a[k][l] == '.') {
              g[get(i, j)].push_back({1, get(k, l)});
              continue;
            }
          }
          if (min(abs(i - k), abs(j - l)) <= 1) {
            if (max(abs(i - k), abs(j - l)) < 3) {
              g[get(i, j)].push_back({1, get(k, l)});
            }
            if (a[k][l] == '.') {
              if (max(abs(i - k), abs(j - l)) == 3) {
                g[get(i, j)].push_back({1, get(k, l)});
              }
            }
          }
        }
      }
    }
  }

  vector<int> d(505 * 505, 1e8);
  auto dijkstra = [&](int s) {
    d[s] = 0;

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
      int u = pq.top()[1];
      int du = pq.top()[0];
      pq.pop();
      if (du > d[u]) {
        continue;
      }
      for (auto p : g[u]) {
        int v = p[1];
        int uv = p[0];
        if (d[u] + uv < d[v]) {
          d[v] = d[u] + uv;
          pq.push({d[v], v});
        }
      }
    }
  };
  dijkstra(get(1, 1));
  cout << d[get(H, W)] << '\n';
}
