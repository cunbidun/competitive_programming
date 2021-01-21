#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e2 + 5;
const int INF = 1e9 + 5;

int n, a[N], f[N][2 * N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= 400; j++) {
      f[i][j] = INF;
    }
  }
  for (int j = 1; j <= 400; j++) {
    f[1][j] = abs(a[1] - j);
  }
  for (int i = 2; i <= n; i++) {
    for (int j = i; j <= 400; j++) {
      for (int k = 1; k < j; k++) {
        f[i][j] = min(f[i][j], f[i - 1][k] + abs(j - a[i]));
      }
    }
  }
  int ans = INF;
  for (int i = 1; i <= 400; i++) {
    ans = min(ans, f[n][i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
