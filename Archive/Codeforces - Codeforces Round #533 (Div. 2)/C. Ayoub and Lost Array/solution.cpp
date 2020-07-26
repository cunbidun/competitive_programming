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
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll addMod(ll x, ll y) {return (x + y) % MOD;}

ll subMod(ll x, ll y) {return ((x - y) % MOD + MOD) % MOD;}

ll mulMod(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}

ll powMod(ll x, ll p) {
    if (p == 0) return 1LL; if (p == 1) return x % MOD;
    ll t = powMod(x, (p/2));
    return (((t * t) % MOD) * powMod(x, p % 2)) % MOD;
}

ll revMod(ll x) {return powMod(x, MOD - 2);}
ll f[MAXA][5],c0,c1,c2;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    int n, l , r;
    cin >> n >> l >> r;
    while(l % 3 != 0) {
        if(l % 3 == 0) c0++;
        if(l % 3 == 1) c1++;
        if(l % 3 == 2) c2++;
        l ++;
    }
    while(r % 3 != 0) {
        if(r % 3 == 0) c0++;
        if(r % 3 == 1) c1++;
        if(r % 3 == 2) c2++;
        r --;
    }
    c0 += ((r - l) / 3 + 1);
    c1 += ((r - l) / 3);
    c2 += ((r - l) / 3);
//    if(r - l + 1 >= 3) {
//        ll ans =  powMod(r - l + 1, n - 1);
//        while(l % 3 != 0) l++;
//        while(r % 3 != 0) r--;
//
//        cout << mulMod(ans, ((r - l)/ 3 + 1));
//        return 0;
//    }
//    if(r - l + 1 == 1) {
//        if(r % 3 == 0) cout << 1;
//        else if(n % 3 == 0) cout << 1;
//        else cout << 0;
//        return 0;
//    }
//    if(r - l + 1 == 2) {
//        ll ans = powMod(r - l + 1, n - 2);
//        cout << addMod(ans, 4);
//        return 0;
//    }
    f[0][0] = 1L;
    rf(i,1,n) {
        f[i][0] = addMod(f[i][0], f[i - 1][0] * c0);
        f[i][0] = addMod(f[i][0], f[i - 1][1] * c2);
        f[i][0] = addMod(f[i][0], f[i - 1][2] * c1);

        f[i][1] = addMod(f[i][1], f[i - 1][1] * c0);
        f[i][1] = addMod(f[i][1], f[i - 1][2] * c2);
        f[i][1] = addMod(f[i][1], f[i - 1][0] * c1);

        f[i][2] = addMod(f[i][2], f[i - 1][1] * c1);
        f[i][2] = addMod(f[i][2], f[i - 1][0] * c2);
        f[i][2] = addMod(f[i][2], f[i - 1][2] * c0);
    }
    cout << f[n][0];
    return 0;
}