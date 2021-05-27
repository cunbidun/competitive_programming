#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int INF = 2e9;

int f[31][31][51];

int solve() {
  int n, m, k;
  cin >> n >> m >> k;
  cout << f[n][m][k] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  memset(f, 63, sizeof(f));

  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 0; k <= 50; k++) {
        if (k == 0 || i * j == k) {
          f[i][j][k] = 0;
        }
      }
    }
  }

  for (int i = 1; i <= 30; i++) {
    for (int j = 1; j <= 30; j++) {
      for (int k = 1; k <= 50; k++) {
        if (i * j < k) {
          break;
        }
        for (int kk = 0; kk <= k; kk++) {
          for (int l = 1; l <= j - 1; l++) {
            f[i][j][k] = min(f[i][j][k], i * i + f[i][l][kk] + f[i][j - l][k - kk]);
            f[i][j][k] = min(f[i][j][k], i * i + f[i][l][k - kk] + f[i][j - l][kk]);
          }
          for (int l = 1; l <= i - 1; l++) {
            f[i][j][k] = min(f[i][j][k], j * j + f[l][j][kk] + f[i - l][j][k - kk]);
            f[i][j][k] = min(f[i][j][k], j * j + f[l][j][k - kk] + f[i - l][j][kk]);
          }
        }
      }
    }
  }

  while (t--) {
    solve();
  }
}