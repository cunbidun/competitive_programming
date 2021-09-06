#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> a(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  int pi = 0, pj = 0;
  for (int i = 1; i <= N - K + 1; i++) {
    for (int j = 1; j <= M - K + 1; j++) {
      int mn = 1e9;
      for (int k = i; k <= i + K - 1; k++) {
        for (int l = j; l <= j + K - 1; l++) {
          mn = min(mn, a[k][l]);
        }
      }
      if (ans < mn) {
        ans = mn;
        pi = i;
        pj = j;
      }
    }
  }
  cout << ans << '\n';
  // cout << pi << ' ' << pj << '\n';
}
