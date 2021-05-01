#include <bits/stdc++.h>

using namespace std;

class Antiqueen {
public:
  int countPaths(int R, int C, int N) {
    int MOD = 1e9 + 7;
    int f[R][C][2];
    memset(f, 0, sizeof(f));
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          f[i][j][0]
        }
      }
      for (int j = 0; j < R; j++) {
        for (int k = 0; k < C; k++) {
          f[j][k][0] = f[j][k][1];
          f[j][k][1] = 0;
        }
      }
    }
    int ans = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        ans = (ans + f[i][j][0]) % MOD;
      }
    }
    cout << ans << '\n';
    return ans;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}
