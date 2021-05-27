#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N], f[N][2];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    f[i][0] = N;
    f[i][1] = N;
  }
  f[1][0] = a[1];
  f[2][0] = a[1] + a[2];
  f[2][1] = a[1];
  for (int i = 3; i <= n; i++) {
    f[i][0] = min(f[i][0], f[i - 1][1] + a[i]);
    f[i][0] = min(f[i][0], f[i - 2][1] + a[i] + a[i - 1]);
    f[i][1] = min(f[i][1], f[i - 1][0]);
    f[i][1] = min(f[i][1], f[i - 2][0]);
  }
  // for(int i =1; i <= n; i++ ) {
  //   cout << min(f[i][0], f[i][1]) << "\n";
  // }
  cout << min(f[n][0], f[n][1]) << "\n";
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