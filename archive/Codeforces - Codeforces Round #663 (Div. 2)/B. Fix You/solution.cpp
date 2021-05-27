#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 105;

int n, m;
char a[N][N];
int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j]; 
    }
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    if (a[n][i] == 'D')
      ans++;
  }

  for (int i = 1; i <= n; i++) {
    if (a[i][m] == 'R')
      ans++;
  }
  cout << ans << "\n";
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