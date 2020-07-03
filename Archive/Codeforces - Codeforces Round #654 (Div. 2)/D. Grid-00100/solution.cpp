#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 1e9;

int res[301][301];
int solve() {
  int n, k;
  cin >> n >> k;
  int K = k;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      res[i][j] = 0;
    }
  }
  int cur = 1;

  int x = 1;
  int y = 1;
  while (k--) {
    res[x][y] = 1;
    x++;
    y++;
    if (y > n) {
      y = 1;
      x = cur + 1;
      cur++;
    }
    if (x > n) {
      x = 1;
    }
  }
  if (K % n != 0) {
    cout << 2 << "\n";
  } else {
    cout << 0 << "\n";
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << res[i][j];
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