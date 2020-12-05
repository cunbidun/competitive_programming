#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, a[N];
ll b[N], l[N], r[N];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    b[i] = 0;
    l[i] = 0;
    r[i] = 0;
  }
  a[0] = a[2];
  a[n + 1] = a[n - 1];

  ll ans = 0;
  for (int i = 1; i < n; i++) {
    ans += abs(a[i] - a[i + 1]);
    b[i] = abs(a[i] - a[i + 1]);
    l[i] = l[i - 1] + b[i];
    // cout << b[i] << " ";
  }
  // cout << "\n";
  for (int i = n - 1; i >= 1; i--) {
    r[i] = r[i + 1] + b[i];
  }
  for (int i = 2; i <= n - 1; i++) {
    ans = min(ans, l[i - 2] + r[i + 1] + 1LL * abs(a[i + 1] - a[i - 1]));
  }
  ans = min(ans, r[2]);
  ans = min(ans, l[n - 2]);
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