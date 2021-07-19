#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h + 2, vector<int>(w + 2));
    vector<vector<int>> b(h + 2, vector<int>(w + 2));
    a[1][1] = 1;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (i == 1 && j == 1) {
          continue;
        }
        if (i == 1 || j == 1 || i == h || j == w) {
          if (a[i - 1][j] != 1 && a[i][j - 1] != 1 && a[i - 1][j - 1] != 1 && a[i - 1][j + 1] != 1) {
            a[i][j] = 1;
          }
        }
      }
    }

    int cnta = 0, cntb = 0;
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cnta += a[i][j];
      }
    }
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        if (i == 1 && j == 1) {
          continue;
        }
        if (i == 1 || j == 1 || i == h || j == w) {
          if (b[i - 1][j] != 1 && b[i][j - 1] != 1 && b[i - 1][j - 1] != 1 && b[i - 1][j + 1] != 1) {
            b[i][j] = 1;
          }
        }
      }
    }
    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cntb += b[i][j];
      }
    }
    if (cnta < cntb) {
      a = b;
    }

    for (int i = 1; i <= h; i++) {
      for (int j = 1; j <= w; j++) {
        cout << a[i][j];
      }
      cout << '\n';
    }
    cout << '\n';
  }
}
