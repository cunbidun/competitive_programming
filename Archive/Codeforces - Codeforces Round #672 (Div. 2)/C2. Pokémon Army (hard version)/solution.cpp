#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
int a[N], n, q;

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  ll ans = a[n];
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i + 1]) {
      ans += a[i] - a[i + 1];
    }
  }
  cout << ans << "\n";
  for (int i = 1; i <= q; i++) {
    int l, r;
    cin >> l >> r;
    if (l != r) {
      if (r == n) {
        ans -= a[r];
        ans += a[l];
      }
      // cout << ans << "\n";
      if (l > 1) {
        if (a[l - 1] > a[l]) {
          ans -= a[l - 1] - a[l];
        }
      }
      if (a[l] > a[l + 1]) {
        ans -= a[l] - a[l + 1];
      }
      if (r < n) {
        if (a[r] > a[r + 1]) {
          ans -= a[r] - a[r + 1];
        }
      }
      if (r > l + 1 && a[r - 1] > a[r]) {
        ans -= a[r - 1] - a[r];
      }
      swap(a[l], a[r]);
      if (l > 1) {
        if (a[l - 1] > a[l]) {
          ans += a[l - 1] - a[l];
        }
      }
      if (a[l] > a[l + 1]) {
        ans += a[l] - a[l + 1];
      }
      if (r < n) {
        if (a[r] > a[r + 1]) {
          ans += a[r] - a[r + 1];
        }
      }
      if (r > l + 1 && a[r - 1] > a[r]) {
        ans += a[r - 1] - a[r];
      }
    }
    cout << ans << "\n";
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