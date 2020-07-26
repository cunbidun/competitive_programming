#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)
#define reset(a,v,b) rf(i, 0, b) a[i] = v

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<ll, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll n, k, inv[100];

vii primeList;

ll addMod(ll x, ll y) {return (x + y) % MOD;}

ll subMod(ll x, ll y) {return ((x - y) % MOD + MOD) % MOD;}

ll mulMod(ll x, ll y) {return ((x ) * (y )) % MOD;}

ll powMod(ll x, ll p) {
    if (p == 0) return 1LL; if (p == 1) return x % MOD;
    ll t = powMod(x, (p/2));
    return (((t * t) % MOD) * powMod(x, p % 2)) % MOD;
}

ll revMod(ll x) {return powMod(x, MOD - 2);}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      // freopen("in.in", "r", stdin);
    #endif

    cin >> n >> k;
    if(n == 1) {
        return cout << 1, 0;
    }
    for(ll i = 2; i * i <= n; i++) {
        int cnt = 0;
        while(n % i == 0) {
            cnt ++;
            n /= i;
        }
        if(cnt) {
           // cout << i << " " << cnt << " " << n << endl;
            primeList.pb(ii(i,cnt));
        }
    }
    if(n != 1) primeList.pb(ii(n, 1));
    //cout << n << endl;
    rf(i, 1, 64) inv[i] = revMod(i);

    ll ans = 1LL;
    rf(x, 0, primeList.size() - 1) {
        int a = primeList[x].S;
        ll p = primeList[x].F;
      //  cout << a << " " << p << endl;
        ll dp[k + 1][a + 1];
        memset(dp, 0LL, sizeof (dp));
        dp[0][a] = 1LL;
        rf(i, 1, k) {
            rb(j, a, 0) {
                rb(l, a, j) {
                    //cout << i << " " << j << " " << l << endl;
                    dp[i][j] = addMod(dp[i][j], mulMod(dp[i - 1][l], inv[l + 1]));
                }
            }
        }
        ll cur = 0;
        rf(j, 0, a) {
            cur = addMod(cur, (dp[k][j] * powMod(p, j)));
        }
        //cout << cur << endl;
        ans = mulMod(cur, ans);
    }
    cout << ans;
    return 0;
}