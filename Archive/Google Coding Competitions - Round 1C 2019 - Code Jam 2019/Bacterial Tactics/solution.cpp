#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; tt++) {
    cout << "Case #" << tt << ": ";
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char>(m));
    int f[16][16][16][16];
    memset(f, -1, sizeof(f));
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> board[i][j];
      }
    }
    function<int(int, int, int, int)> solve = [&](int x1, int y1, int x2, int y2) {
      if (x1 == x2 || y1 == y2) {
        return 0;
      }
      if (f[x1][y1][x2][y2] != -1) {
        return f[x1][y1][x2][y2];
      }
      set<int> l;
      for (int i = x1; i < x2; i++) {
        int ok = 1;
        for (int j = y1; j < y2; j++) {
          if (board[i][j] == '#') {
            ok = 0;
          }
        }
        if (ok) {
          l.insert(solve(x1, y1, i, y2) ^ solve(i + 1, y1, x2, y2));
        }
      }
      for (int i = y1; i < y2; i++) {
        int ok = 1;
        for (int j = x1; j < x2; j++) {
          if (board[j][i] == '#') {
            ok = 0;
          }
        }
        if (ok) {
          l.insert(solve(x1, y1, x2, i) ^ solve(x1, i + 1, x2, y2));
        }
      }
      int count = 0;
      while (l.find(count) != l.end()) {
        count++;
      }
      return f[x1][y1][x2][y2] = count;
    };
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int ok = 1;
      for (int j = 0; j < m; j++) {
        if (board[i][j] == '#') {
          ok = 0;
        }
      }
      if (ok) {
        if ((solve(0, 0, i, m) ^ solve(i + 1, 0, n, m)) == 0) {
          ans += m;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      int ok = 1;
      for (int j = 0; j < n; j++) {
        if (board[j][i] == '#') {
          ok = 0;
        }
      }
      if (ok) {
        if ((solve(0, 0, n, i) ^ solve(0, i + 1, n, m)) == 0) {
          ans += n;
        }
      }
    }
    cout << ans << "\n";
  }
}
