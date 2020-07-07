#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int a[301][301];
int solve() {
  int n, m;
  cin >> n >> m;
  int f = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (i == 1 || i == n || j == 1 || j == m) {
        if (a[i][j] > 3) {
          f = 1;
        }
      } else {
        if (a[i][j] > 4) {
          f = 1;
        }
      }
    }
  }
  if (f) {
    cout << "NO\n";
    return 0;
  }
  if (a[1][1] > 2 || a[1][m] > 2 || a[n][1] > 2 || a[n][m] > 2) {
    cout << "NO\n";
    return 0;
  }
  cout << "YES\n";
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if ((i == 1 && j == 1) || (i == 1 && j == m) || (i == n && j == 1) || (i == n && j == m)) {
        cout << 2 << " ";
      } else if (i == 1 || i == n || j == 1 || j == m) {
        cout << 3 << " ";
      } else {
        cout << 4 << " ";
      }
    }
		cout << "\n";
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