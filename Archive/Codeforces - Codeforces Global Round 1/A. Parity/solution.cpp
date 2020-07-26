#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 2;
               const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll addMod(ll x, ll y) {
    return (x + y) % MOD;
}

ll subMod(ll x, ll y) {
    return ((x - y) % MOD + MOD) % MOD;
}

ll mulMod(ll x, ll y) {
    return ((x % MOD) * (y % MOD)) % MOD;
}

ll powMod(ll x, ll p) {
    if (p == 0)
        return 1LL;
    if (p == 1)
        return x % MOD;
    ll t = powMod(x, (p/2));
    return (((t * t) % MOD) * powMod(x, p % 2)) % MOD;
}

ll revMod(ll x) {
    return powMod(x, MOD - 2);
}

int b,k;
int a[MAXA];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
#endif
    cin >> b >> k;
    rf(i,0,k-1) cin >> a[i];
    ll ans = 0;
    int  cur = 0;
    rb(i,k-1,0) {
        ans = addMod(ans, mulMod(a[cur], powMod(b, i)));
        cur ++;
    }
    if(ans)
        cout << "odd";
    else
        cout << "even";
    return 0;
}