#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 5;

int n, k, pre, f[N][N], ch[N][N];
char a[N][N];
string ans = "";
set<ii> pos;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      f[i][j] = (a[i][j] == 'a') + max(f[i][j - 1], f[i - 1][j]);
      if (i + j - 1 - f[i][j] <= k) {
        ch[i][j] = 1;
        pre = max(pre, i + j - 1);
      }
    }
  }
  for (int i = 1; i <= pre; i++) {
    ans += 'a';
  }

  if (pre != 0) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (i + j - 1 == pre && ch[i][j] == 1) {
          if (i < n) {
            pos.insert({i + 1, j});
          }
          if (j < n) {
            pos.insert({i, j + 1});
          }
        }
      }
    }
  } else {
    pos.insert({1, 1});
  }

  while (sz(pos) != 0) {
    char mn = '|';
    for (ii p : pos) {
      mn = min(mn, a[p.first][p.second]);
    }
    ans += mn;
    set<ii> new_pos;
    for (ii p : pos) {
      int i = p.first;
      int j = p.second;
      if (i < n) {
        if (mn == a[i][j]) {
          new_pos.insert({i + 1, j});
        }
      }
      if (j < n) {
        if (mn == a[i][j]) {
          new_pos.insert({i, j + 1});
        }
      }
    }
    pos = new_pos;
  }
  cout << ans << "\n";
}