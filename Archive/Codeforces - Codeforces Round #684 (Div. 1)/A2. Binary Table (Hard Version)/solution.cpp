#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 105;
int n, m, a[N][N];

struct e {
  ii p1, p2, p3;
};

vector<e> ans;

void flip(ii p1, ii p2, ii p3) {
  a[p1.first][p1.second] = 1 - a[p1.first][p1.second];
  a[p2.first][p2.second] = 1 - a[p2.first][p2.second];
  a[p3.first][p3.second] = 1 - a[p3.first][p3.second];
  ans.push_back({p1, p2, p3});
}

void solve() {
  ans.clear();
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      a[i][j] = c - '0';
    }
  }

  for (int i = 1; i <= n - 2; i++) {
    for (int j = 1; j <= m; j++) {
      if (a[i][j] == 1) {
        if (j == m) {
          flip({i, j}, {i + 1, j}, {i + 1, j - 1});
        } else {
          flip({i, j}, {i + 1, j}, {i, j + 1});
        }
      }
    }
  }
  for (int i = 1; i <= m - 2; i++) {
    if (a[n - 1][i] == 1) {
      flip({n - 1, i}, {n - 1, i + 1}, {n, i});
    }
    if (a[n][i] == 1) {
      flip({n, i}, {n, i + 1}, {n - 1, i + 1});
    }
  }
  array<int, 4> p[5];
  p[0] = {1, 1, 1, 0};
  p[1] = {1, 1, 0, 1};
  p[2] = {1, 0, 1, 1};
  p[3] = {0, 1, 1, 1};
  ii t[] = {{1, 1}, {1, 0}, {0, 1}, {0, 0}};

  for (int i = 0; i < 16; i++) {
    int x[] = {a[n - 1][m - 1], a[n - 1][m], a[n][m - 1], a[n][m]};
    for (int j = 0; j < 4; j++) {
      if (((i >> j) & 1) == 1) {
        for (int k = 0; k < 4; k++) {
          x[k] += p[j][k];
        }
      }
    }
    int f = 0;
    for (int j = 0; j < 4; j++) {
      f += x[j] % 2;
    }
    if (f == 0) {
      for (int j = 0; j < 4; j++) {
        if (((i >> j) & 1) == 1) {
          ii q[3];
          int cnt = 0;
          for (int k = 0; k < 4; k++) {
            if (p[j][k] == 1) {
              q[cnt++] = {n - t[k].first, m - t[k].second};
            }
          }
          flip(q[0], q[1], q[2]);
        }
      }
      cout << ans.size() << "\n";
      for (auto [p1, p2, p3] : ans) {
        cout << p1.first << " " << p1.second << " ";
        cout << p2.first << " " << p2.second << " ";
        cout << p3.first << " " << p3.second << "\n";
      }
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
