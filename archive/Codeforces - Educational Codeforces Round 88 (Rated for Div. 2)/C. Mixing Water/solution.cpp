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

ll h, c, t;

bool ch(ll x) { return (x + 1) * h + c * x >= t * (2 * x + 1); }

int solve() {
  cin >> h >> c >> t;
  if (t * 2 <= h + c) return cout << 2 << "\n", 0;
  ll l = 0, r = 1e12;
  while (l != r) {
    if (l + 1 == r) {
      if (ch(r)) l = r;
      break;
    }
    ll m = (l + r) / 2;
    if (ch(m))
      l = m;
    else
      r = m - 1;
  }
  ll ans = 0;
  if (abs(1.0 * ((l + 1) * h + c * l) / (2 * l + 1) - t) >
      abs(1.0 * ((l + 2) * h + c * (l + 1)) / (2 * (l + 1) + 1) - t))
    ans = 2 * (l + 1) + 1;
  else
    ans = 2 * l + 1;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}