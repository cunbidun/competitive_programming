#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const ll INF = 2e12;

ll solve(int la, int lb, int ra, int rb, int ta, int tb) {
  int a = ra - la + 1;
  int b = rb - lb + 1;
  int mx = lb - la;
  int gcd = __gcd(ta, tb);
  int cur = mx / gcd;
  ll mxv = -INF;
  for (int i = cur - 2; i <= cur + 2; i++) {
    if (1LL * i * gcd - mx <= 0) {
      mxv = max(mxv, 1LL * i * gcd - mx);
    }
  }
  return min(1LL * b, a + mxv);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int la, ra, ta, lb, rb, tb;
  cin >> la >> ra >> ta;
  cin >> lb >> rb >> tb;
  ll ans = max(solve(lb, la, rb, ra, tb, ta), solve(la, lb, ra, rb, ta, tb));
	cout << max(0LL, ans);
}