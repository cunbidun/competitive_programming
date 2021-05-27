#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e3 + 4;

int n, m, c[N][N], f[N][N];
ll ans = 0;
char a[N][N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  ans = n * m;
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 2; j <= m - 1; j++) {
      c[i][j] = 1;
      if (a[i][j] != a[i - 1][j]) {
        c[i][j] = 0;
      }
      if (a[i][j] != a[i + 1][j]) {
        c[i][j] = 0;
      }
      if (a[i][j] != a[i][j - 1]) {
        c[i][j] = 0;
      }
      if (a[i][j] != a[i][j + 1]) {
        c[i][j] = 0;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (c[i][j] != 0) {
        f[i][j] = 1e9;
      }
    }
  }
  for (int i = 2; i <= n - 1; i++) {
    for (int j = 2; j <= m - 1; j++) {
      f[i][j] = min(f[i][j], min(f[i - 1][j], f[i][j - 1]) + 1);
    }
  }
  for (int i = n - 1; i >= 2; i--) {
    for (int j = m - 1; j >= 2; j--) {
      f[i][j] = min(f[i][j], min(f[i + 1][j], f[i][j + 1]) + 1);
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      ans += f[i][j];
    }
  }
  cout << ans << "\n";
}