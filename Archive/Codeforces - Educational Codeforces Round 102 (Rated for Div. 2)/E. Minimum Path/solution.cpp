#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const ll INF = 1e15;
int n, m;

vector<pair<int, int>> a[N];
ll d[N][2][2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  set<array<ll, 4>> pq;
  for (int i = 1; i <= n; i++) {
    d[i][0][0] = d[i][0][1] = d[i][1][0] = d[i][1][1] = INF;
  }
  d[1][0][0] = 0;
  pq.insert({0, 1, 0, 0});
  while (!pq.empty()) {
    auto [du, u, add, sub] = *pq.begin();
    pq.erase(pq.begin());
    for (auto [v, uv] : a[u]) {
      for (int i = 0; i <= 1 - add; i++) {
        for (int j = 0; j <= 1 - sub; j++) {
          int w = 1 + i - j;
          int na = add | i;
          int ns = sub | j;
          if (d[v][na][ns] > du + uv * w) {
            auto it = pq.find({d[v][na][ns], v, na, ns});
            if (it != pq.end()) {
              pq.erase(it);
            }
            d[v][na][ns] = du + uv * w;
            pq.insert({d[v][na][ns], v, na, ns});
          }
        }
      }
    }
  }

  for (int i = 2; i <= n; i++) {
    cout << d[i][1][1] << " ";
  }
  cout << "\n";
}
