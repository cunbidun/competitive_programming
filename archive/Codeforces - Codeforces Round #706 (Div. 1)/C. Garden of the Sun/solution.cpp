#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> a(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> a[i][j];
      }
    }
    if (n == 1) {
      for (int i = 0; i < m; i++) {
        cout << 'X';
      }
      cout << '\n';
      continue;
    }
    for (int i = 1; i < n; i += 3) {
      for (int j = 0; j < m; j++) {
        a[i][j] = 'X';
      }
    }

    for (int i = 2; i < n; i += 3) {
      if (i + 1 == n) {
        break;
      }
      int ok = 0;
      for (int j = 0; j < m; j++) {
        if (a[i][j] == 'X') {
          a[i + 1][j] = 'X';
          ok = 1;
          break;
        }
      }
      if (!ok) {
        for (int j = 0; j < m; j++) {
          if (a[i + 1][j] == 'X') {
            a[i][j] = 'X';
            ok = 1;
            break;
          }
        }
      }
      if (!ok) {
        a[i][0] = 'X';
        a[i + 1][0] = 'X';
      }
    }
    if (n % 3 == 1) {
      for (int i = 0; i < m; i++) {
        if (a[n - 1][i] == 'X') {
          a[n - 2][i] = 'X';
        }
      }
    }
    for (auto v : a) {
      for (char i : v) {
        cout << i;
      }
      cout << '\n';
    }
  }
}
