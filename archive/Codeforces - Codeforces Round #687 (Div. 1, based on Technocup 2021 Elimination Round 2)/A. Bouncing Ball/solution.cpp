#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

int n, k, p, s[N], x, y;
char a[N];

void solve() {
  cin >> n >> p >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = 0;
  }
  cin >> x >> y;
  for (int i = n; i >= n - k + 1; i--) {
    s[i] = 1 - (a[i] - '0');
  }
  for (int i = n - k; i >= 1; i--) {
    s[i] = s[i + k] + (1 - (a[i] - '0'));
  }
  ll ans = 2e9;
  for (int i = 0; i <= n - p; i++) {
    ans = min(ans, 1LL * i * y + 1LL * s[p + i] * x);
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