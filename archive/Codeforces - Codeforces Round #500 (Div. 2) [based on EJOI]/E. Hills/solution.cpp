#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 5e3 + 5;
const int INF = 1e9 + 7;

int n, f[N][N / 2][2], a[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i <= N - 1; i++) {
    for (int j = 0; j <= N / 2 - 1; j++) {
      f[i][j][0] = INF;
      f[i][j][1] = INF;
    }
  }
  for (int i = 0; i <= n; i++) {
    f[i][0][0] = 0;
  }
  f[1][1][1] = 0;

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= (n + 1) / 2; j++) {
      f[i][j][0] = min(f[i - 1][j][0], f[i - 1][j][1] + max(0, a[i] - (a[i - 1] - 1)));
      f[i][j][1] = min(f[i - 2][j - 1][0] + max(0, a[i - 1] - (a[i] - 1)),
                       f[i - 2][j - 1][1] + max(0, a[i - 1] - (min(a[i], a[i - 2]) - 1)));
    }
  }
  for (int i = 1; i <= (n + 1) / 2; i++) {
    cout << min(f[n][i][0], f[n][i][1]) << " ";
  }
  cout << "\n";
}