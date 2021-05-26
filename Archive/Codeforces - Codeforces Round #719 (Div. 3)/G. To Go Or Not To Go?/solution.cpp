#include <bits/stdc++.h>

using namespace std;

int main() {
  long long INF = 1e18;
  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, W;
  cin >> N >> M >> W;
  auto get = [&](array<int, 2> x) -> int {
    return x[0] * M + x[1];
  };
  auto in = [&](array<int, 2> x) -> bool {
    return 0 <= x[0] && x[0] < N && 0 <= x[1] && x[1] < M;
  };
  vector<vector<int>> a(N, vector<int>(M));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> a[i][j];
    }
  }
  auto bfs = [&](vector<long long> &d, array<int, 2> seed) {
    queue<array<int, 2>> q;
    q.push(seed);
    d.assign(N * M, INF);
    d[get(seed)] = 0;
    vector<int> visited(N * M);
    visited[get(seed)] = 1;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (int i = 0; i < 4; i++) {
        int nx = u[0] + dx[i];
        int ny = u[1] + dy[i];
        int idx = get({nx, ny});
        if (in({nx, ny}) && a[nx][ny] != -1 && !visited[idx]) {
          visited[idx] = 1;
          d[idx] = min(d[idx], d[get(u)] + W);
          q.push({nx, ny});
        }
      }
    }
  };
  vector<long long> d0, dN;
  bfs(d0, {0, 0});
  bfs(dN, {N - 1, M - 1});
  long long mn0 = INF, mnN = INF;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] > 0) {
        mn0 = min(mn0, d0[get({i, j})] + a[i][j]);
        mnN = min(mnN, dN[get({i, j})] + a[i][j]);
      }
    }
  }
  long long ans = min(mn0 + mnN, d0[get({N - 1, M - 1})]);
  cout << ((ans == INF) ? -1 : ans) << '\n';
}
