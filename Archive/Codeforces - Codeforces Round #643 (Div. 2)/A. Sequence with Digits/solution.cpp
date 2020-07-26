#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

ll mx(ll a) {
  ll ans = 0;
  while (a) {
    ans = max(a % 10, ans);
    a /= 10;
  }
  return ans;
}

ll mn(ll a) {
  ll ans = 10;
  while (a) {
    ans = min(a % 10, ans);
    a /= 10;
  }
  return ans;
}

int solve() {
  ll ans, k;
  cin >> ans >> k;
	k--;
  while (k--) {
    if (mn(ans) == 0) {
      break;
    }
    ans += (mx(ans) * mn(ans));
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