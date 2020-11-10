#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  ll ans = 0, n, k;
  cin >> n >> k;
  for (ll ab = 2; ab <= 2 * n; ab++) {
    ll cd = ab - k;
    if (cd < 2 || cd > 2 * n) {
      continue;
    }
    ll res = (ab - 1);
    if (ab > n) {
      res = (n - (ab - n) + 1);
    }
    if (cd <= n) {
      ans += res * (cd - 1);
    } else {
      ans += res * (n - (cd - n) + 1);
    }
    // cout << ab << " " << cd << " " << ans << "\n";
  }
  cout << ans << "\n";
}