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

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  ll ans = 0;
  for (ll y = b; y <= c; y++) {
    ll st = max(a, c + 1 - y);
    if (st > b) continue;
    ll count = min(st + y - 1 - c + 1, d - c + 1);
    ll l = min(d - c + 1 - count + 1, b - st + 1);
    ans += (l + 1) * l / 2 + (count - 1) * l;
    ans += (d - c + 1) * max(0LL, b - (st + l) + 1);
  }
  cout << ans << "\n";
}