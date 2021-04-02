#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, C, K;
    cin >> R >> C >> K;
    vector<vector<int>> V(R, vector<int>(C));
    vector<vector<int>> l(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> V[i][j];
        int mn = V[i][j], mx = V[i][j];
        for (int k = j; k >= 0; k--) {
          mn = min(mn, V[i][k]);
          mx = max(mx, V[i][k]);
          if (mx - mn > K) {
            break;
          }
          l[i][j] = j - k + 1;
        }
      }
    }
    int ans = 0;
    for (int col = 0; col < C; col++) {
      for (int row = 0; row < R; row++) {
        int up, down;
        for (up = row; up >= 0; up--) {
          if (l[up][col] < l[row][col]) {
            break;
          }
        }
        up++;
        for (down = row; down < R; down++) {
          if (l[down][col] < l[row][col]) {
            break;
          }
        }
        down--;
        ans = max(ans, (down - up + 1) * l[row][col]);
      }
    }
    cout << ans << '\n';
  }
}
