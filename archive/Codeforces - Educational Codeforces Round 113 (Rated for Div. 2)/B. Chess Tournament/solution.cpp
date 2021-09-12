#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    vector<vector<char>> ans(N + 1, vector<char>(N + 1, '*'));
    for (int i = 1; i <= N; i++) {
      char c;
      cin >> c;
      a[i] = c - '0';
      ans[i][i] = 'X';
    }
    for (int i = 1; i <= N; i++) {
      if (a[i] == 1) {
        for (int j = 1; j <= N; j++) {
          if (i != j) {
            ans[i][j] = '=';
            ans[j][i] = '=';
          }
        }
      }
    }
    int f = 0;
    for (int i = 1; i <= N; i++) {
      if (a[i] == 2) {
        int pos = -1;
        for (int j = 1; j <= N; j++) {
          if (ans[i][j] == '*') {
            pos = j;
            break;
          }
        }
        if (pos == -1) {
          f = 1;
          break;
        }
        ans[i][pos] = '+';
        ans[pos][i] = '-';
      }
    }

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        if (ans[i][j] == '*') {
          ans[i][j] = '+';
          ans[j][i] = '-';
        }
      }
    }
    if (f) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
          cout << ans[i][j];
        }
        cout << "\n";
      }
    }
  }
}
