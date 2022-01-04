#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<array<int, 2>>> f(N + 1, vector<array<int, 2>>(M + 1));
  vector<vector<int>> b(N + 1, vector<int>(M + 1));
  for (int i = N; i >= 1; i--) {
    for (int j = M; j >= 1; j--) {
      if (i != N) {
        f[i][j][1] = f[i + 1][j][0] + 1;
      }
      if (j != M) {
        f[i][j][0] = f[i][j + 1][1] + 1;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      ans += f[i][j][0] + f[i][j][1] + 1;
      // cout << f[i][j][0] + f[i][j][1] + 1 << ' ';
    }
    // cout << '\n';
  }

  // cout << ans << '\n';
  while (Q--) {
    int x, y;
    cin >> x >> y;
    if (b[x][y] == 0) {
      b[x][y] = 1;
      ans -= f[x][y][0] + f[x][y][1] + 1;
      f[x][y][0] = f[x][y][1] = 0;
    } else {
      b[x][y] = 0;
      if (x != N) {
        f[x][y][1] = f[x + 1][y][0] + (b[x + 1][y] != 1);
      }
      if (y != M) {
        f[x][y][0] = f[x][y + 1][1] + (b[x][y + 1] != 1);
      }
      ans += f[x][y][0] + f[x][y][1] + 1;
    }
    // cout << x << ' ' << y << '\n';
    for (int i = x; i >= 1; i--) {
      for (int j = y - (x - i) + 1; j >= y - (x - i) - 1; j--) {
        if ((i == x && j == y) || !(1 <= j && j <= y) || b[i][j] == 1) {
          continue;
        }
        int n1 = 0, n0 = 0;
        if (i != N) {
          n1 = f[i + 1][j][0] + (b[i + 1][j] != 1);
        }
        if (j != M) {
          n0 = f[i][j + 1][1] + (b[i][j + 1] != 1);
        }
        ans += n1 + n0 - f[i][j][1] - f[i][j][0];
        // if (i == 1 && j == 1) {
        //   cout << f[i][j + 1][0] << '\n';
        //   cout << n0 << ' ' << n1 << '\n';
        // }
        f[i][j][0] = n0;
        f[i][j][1] = n1;
      }
    }

    // for (int i = 1; i <= N; i++) {
    //   for (int j = 1; j <= M; j++) {
    //     cout << f[i][j][0] + f[i][j][1] + (b[i][j] != 1) << ' ';
    //   }
    //   cout << '\n';
    // }
    // cout << '\n';
    cout << ans << '\n';
  }
}
