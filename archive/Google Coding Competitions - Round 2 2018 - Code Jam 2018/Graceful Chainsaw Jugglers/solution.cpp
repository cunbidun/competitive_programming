#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> f(501, vector<int>(501, -1));
  f[0][0] = 0;
  for (int x = 0; x <= 35; x++) {
    for (int y = 0; y <= 35; y++) {
      if (x + y == 0) {
        continue;
      }
      for (int i = 500 - x; i >= 0; i--) {
        for (int j = 500 - y; j >= 0; j--) {
          f[i + x][j + y] = max(f[i + x][j + y], f[i][j] + 1);
        }
      }
    }
  }
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, B;
    cin >> R >> B;
    cout << f[R][B] << '\n';
  }
}
