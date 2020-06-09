#include <bits/stdc++.h>

#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;

int n, m;
char a[51][51];
int vis[51][51];
int d = 0;

void dfs(int i, int j) {
  if (vis[i][j] || a[i][j] == '#') return;
  if (a[i][j] == 'B') d = -1e9;
  if (a[i][j] == 'G') d++;
  vis[i][j] = 1;
  if (i > 1) dfs(i - 1, j);
  if (i < n) dfs(i + 1, j);
  if (j > 1) dfs(i, j - 1);
  if (j < m) dfs(i, j + 1);
}

int solve() {
  int cnt = 0;
  d = 0;
  cin >> n >> m;
  rf(i, 1, n) rf(j, 1, m) {
    vis[i][j] = 0;
    cin >> a[i][j];
    if (a[i][j] == 'G') cnt++;
  }
  rf(i, 1, n) rf(j, 1, m) {
    if (a[i][j] == 'B') {
      if (i > 1 && a[i - 1][j] == '.') a[i - 1][j] = '#';
      if (i < n && a[i + 1][j] == '.') a[i + 1][j] = '#';
      if (j > 1 && a[i][j - 1] == '.') a[i][j - 1] = '#';
      if (j < m && a[i][j + 1] == '.') a[i][j + 1] = '#';
    }
  }
  if (cnt == 0) return cout << "Yes\n", 0;
  dfs(n, m);
  if (vis[n][m] && d == cnt)
    cout << "Yes\n";
  else
    cout << "No\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}