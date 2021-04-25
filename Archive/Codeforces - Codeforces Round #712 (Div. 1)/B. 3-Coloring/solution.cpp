#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> g(n, vector<int>(n, 0));
  for (int i = 0; i < n * n; i++) {
    int a;
    cin >> a;
    if (a == 1) {
      int d = 0;
      for (int j = 0; j < n; j++) {
        if (d) {
          break;
        }
        for (int k = 0; k < n; k++) {
          if ((j + k) % 2 == 1 && g[j][k] == 0) {
            cout << 2 << ' ' << j + 1 << ' ' << k + 1 << endl;
            g[j][k] = 2;
            d = 1;
            break;
          }
        }
      }
      for (int j = 0; j < n; j++) {
        if (d) {
          break;
        }
        for (int k = 0; k < n; k++) {
          if ((j + k) % 2 == 0 && g[j][k] == 0) {
            cout << 3 << ' ' << j + 1 << ' ' << k + 1 << endl;
            g[j][k] = 3;
            d = 1;
            break;
          }
        }
      }
    }

    if (a == 2) {
      int d = 0;
      for (int j = 0; j < n; j++) {
        if (d) {
          break;
        }
        for (int k = 0; k < n; k++) {
          if ((j + k) % 2 == 0 && g[j][k] == 0) {
            cout << 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
            g[j][k] = 1;
            d = 1;
            break;
          }
        }
      }
      for (int j = 0; j < n; j++) {
        if (d) {
          break;
        }
        for (int k = 0; k < n; k++) {
          if ((j + k) % 2 == 1 && g[j][k] == 0) {
            cout << 3 << ' ' << j + 1 << ' ' << k + 1 << endl;
            g[j][k] = 3;
            d = 1;
            break;
          }
        }
      }
    }

    if (a == 3) {
      int d = 0;
      for (int j = 0; j < n; j++) {
        if (d) {
          break;
        }
        for (int k = 0; k < n; k++) {
          if (g[j][k] == 0) {
            if ((j + k) % 2 == 0) {
              cout << 1 << ' ' << j + 1 << ' ' << k + 1 << endl;
              g[j][k] = 1;
            } else {
              cout << 2 << ' ' << j + 1 << ' ' << k + 1 << endl;
              g[j][k] = 2;
            }
            d = 1;
            break;
          }
        }
      }
    }
  }
}
