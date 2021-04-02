#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int dx[] = {1, -1, 0, 0};
  int dy[] = {0, 0, -1, 1};
  char c[] = {'D', 'U', 'L', 'R'};
  char cc[] = {'U', 'D', 'R', 'L'};

  int n;
  cin >> n;
  vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j].first >> a[i][j].second;
      if (a[i][j] != make_pair(-1, -1)) {
        a[i][j].first--;
        a[i][j].second--;
      }
    }
  }
  vector<vector<char>> ans(n, vector<char>(n, '!'));
  queue<pair<int, int>> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == make_pair(i, j)) {
        ans[i][j] = 'X';
        q.push({i, j});
      }
    }
  }
  auto inside = [&](int i, int j) {
    return i >= 0 && j >= 0 && i < n && j < n;
  };
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int nx = u.first + dx[i];
      int ny = u.second + dy[i];
      if (inside(nx, ny) && ans[nx][ny] == '!' && a[nx][ny] == a[u.first][u.second]) {
        ans[nx][ny] = cc[i];
        q.push({nx, ny});
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] != make_pair(-1, -1)) {
        if (ans[i][j] == '!') {
          cout << "INVALID\n";
          return 0;
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == '!') {
        int ok = 0;
        for (int k = 0; k < 4; k++) {
          if (inside(i + dx[k], j + dy[k]) && ans[i + dx[k]][j + dy[k]] == '!') {
            ok = 1;
          }
        }
        if (!ok) {
          cout << "INVALID\n";
          return 0;
        }
      }
    }
  }

  function<void(int, int)> dfs = [&](int i, int j) {
    for (int k = 0; k < 4; k++) {
      int nx = i + dx[k];
      int ny = j + dy[k];
      if (inside(nx, ny) && ans[nx][ny] == '!') {
        if (ans[i][j] == '!') {
          ans[i][j] = c[k];
        }
        ans[nx][ny] = cc[k];
        dfs(nx, ny);
      }
    }
  };

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ans[i][j] == '!') {
        dfs(i, j);
      }
    }
  }
  cout << "VALID\n";
  for (auto v : ans) {
    for (auto c : v) {
      cout << c;
    }
    cout << '\n';
  }
}
