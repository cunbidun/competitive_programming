#include <bits/stdc++.h>

using namespace std;

int n;
int m[301][301];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> m[i][j];
    }
  }
  int k;
  cin >> k;
  while (k--) {
    int u, v, w;
    cin >> u >> v >> w;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        m[i][j] = min(m[i][j], m[u][i] + w + m[v][j]);
        m[i][j] = min(m[i][j], m[u][j] + w + m[v][i]);
      }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        ans += m[i][j];
      }
    }
    cout << ans / 2 << " ";
  }
  cout << "\n";
}