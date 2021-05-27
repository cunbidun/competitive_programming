#include <bits/stdc++.h>

using namespace std;

int h[505][505], v[505][505], f[505][505][21];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  if (k % 2 != 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << -1 << ' ';
      }
      cout << '\n';
    }
    return 0;
  }
  for (int i = 0; i <= n + 1; i++) {
    for (int j = 0; j <= m + 1; j++) {
      for (int kp = 0; kp <= k; kp++) {
        f[i][j][kp] = 1e9;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m - 1; j++) {
      cin >> h[i][j];
    }
  }
  for (int i = 1; i <= n - 1; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> v[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      f[i][j][0] = 0;
    }
  }
  for (int kp = 1; kp <= k / 2; kp++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        f[i][j][kp] = min(f[i][j][kp], f[i][j - 1][kp - 1] + h[i][j - 1]);
        f[i][j][kp] = min(f[i][j][kp], f[i][j + 1][kp - 1] + h[i][j]);
        f[i][j][kp] = min(f[i][j][kp], f[i - 1][j][kp - 1] + v[i - 1][j]);
        f[i][j][kp] = min(f[i][j][kp], f[i + 1][j][kp - 1] + v[i][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << f[i][j][k / 2] * 2 << ' ';
    }
    cout << '\n';
  }
}
