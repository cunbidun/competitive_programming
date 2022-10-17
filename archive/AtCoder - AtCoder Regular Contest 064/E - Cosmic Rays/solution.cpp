#include <array>
#include <functional>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(9);
  int xs, ys, xt, yt;
  cin >> xs >> ys >> xt >> yt;
  int N;
  cin >> N;
  vector<array<int, 3>> a(N + 2);
  for (int i = 1; i <= N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
  }
  a[0][0] = xs;
  a[0][1] = ys;
  a[0][2] = 0;
  a[N + 1][0] = xt;
  a[N + 1][1] = yt;
  a[N + 1][2] = 0;
  auto distance = [&](int i, int j) -> double {
    int x1 = a[i][0], y1 = a[i][1], r1 = a[i][2];
    int x2 = a[j][0], y2 = a[j][1], r2 = a[j][2];
    return max(sqrt(1.0 * (x1 - x2) * (x1 - x2) + 1.0 * (y1 - y2) * (y1 - y2)) - r1 - r2, 0.0);
  };
  vector<double> d(N + 2, 2e18);
  vector<bool> visited(N + 2, false);
  auto dijkstra = [&]() -> void {
    d[0] = 0;
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> q;
    q.push({0.0, 0});
    while (!q.empty()) {
      auto [du, u] = q.top();
      q.pop();
      if (visited[u]) {
        continue;
      }
      visited[u] = true;
      for (int v = 0; v <= N + 1; v++) {
        if (!visited[v]) {
          double uv = distance(u, v);
          if (d[v] <= d[u] + uv) {
            continue;
          }
          d[v] = d[u] + uv;
          q.push({d[v], v});
        }
      }
    }
  };
  dijkstra();
  cout << d[N + 1] << '\n';
}
