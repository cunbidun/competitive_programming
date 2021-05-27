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

ll a[70], f[70];
ll cal(ll n) {
  if (n == 0) return 0;
  int p = 0;
  ll ans = 0;
  ll cur = 1;
  while (cur * 2 <= n) {
    cur *= 2;
    p++;
  }
  ans += p + 1 + f[p] + cal(n - (1LL << p));
  return ans;
}
int solve() {
  ll n;
  cin >> n;
  cout << cal(n) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  f[0] = 0;
  rf(i, 1, 62) { f[i] = 2LL * f[i - 1] + i; }
  cin >> t;
  while (t--) solve();
}