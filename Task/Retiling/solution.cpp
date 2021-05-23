#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int R, C, F, S;
    cin >> R >> C >> F >> S;
    vector<vector<char>> a(R, vector<char>(C));
    vector<vector<char>> b(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> a[i][j];
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> b[i][j];
      }
    }
    int ans = 0;
    map<array<int, 2>, vector<array<int, 2>>> v;
    map<array<int, 2>, int> visited;
    int tot = 0;
    int out = 0;
    function<void(array<int, 2>)> dfs = [&](array<int, 2> u) {
      visited[u] = 1;
      tot++;
      int cnt = 0;
      for (auto p : v[u]) {
        if (!visited[p]) {
          dfs(p);
          // cout << p[0] << ' ' << p[1] << ' ' << v[p].size() << '\n';
          if (v[p].size() == 1) {
            cnt++;
          }
        }
      }
      // cout << u[0] << ' ' << u[1] << ' ' << cnt << '\n';
      out += max(0, cnt - 1);
    };
    v[{}] = 1;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (a[i][j] != b[i][j]) {
          int ok = 0;
          if (i > 0 && a[i][j] != a[i - 1][j] && a[i - 1][j] != b[i - 1][j]) {
            v[{i, j}].push_back({i - 1, j});
            ok = 1;
          }
          if (i < R - 1 && a[i][j] != a[i + 1][j] && a[i + 1][j] != b[i + 1][j]) {
            v[{i, j}].push_back({i + 1, j});
            ok = 1;
          }
          if (j > 0 && a[i][j] != a[i][j - 1] && a[i][j - 1] != b[i][j - 1]) {
            v[{i, j}].push_back({i, j - 1});
            ok = 1;
          }
          if (j < C - 1 && a[i][j] != a[i][j + 1] && a[i][j + 1] != b[i][j + 1]) {
            v[{i, j}].push_back({i, j + 1});
            ok = 1;
          }
          ans += (1 - ok);
        }
      }
    }
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (!visited[{i, j}] && v[{i, j}].size() > 0) {
          tot = 0;
          out = 0;
          dfs({i, j});
          // cout << i << ' ' << j << ' ' << out << ' ' << tot << '\n';
          ans += out + (tot - out + 1) / 2;
        }
      }
    }
    cout << ans << '\n';
  }
}
