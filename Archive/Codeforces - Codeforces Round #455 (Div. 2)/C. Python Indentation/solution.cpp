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

const int INF = 2e9 + 7;
const int MAXA = 5e3 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

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

ll f[MAXA][MAXA];
int n;
char a[MAXA];
bool v[MAXA][MAXA];

ll sol(int i, int d) {
	//cout << i << " " << d << endl;
	if(v[i][d]) return f[i][d];
	v[i][d] = 1;
	if(i == n - 1) {
		if(a[i] == 'f') return f[i][d] = 1LL;
		return f[i][d] = 1LL * d;
	}
	
	if(a[i] == 'f') {
		f[i][d] = sol(i + 1, d + 1);
	} 
	else {
		if(v[i][d - 1]) return f[i][d] = addMod(f[i][d - 1], sol(i + 1, d));
		rf(j, 1, d) {
			f[i][d] = addMod(f[i][d], sol(i + 1, j));
		}
	}
	return f[i][d];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    if(n == 1) return cout << 1, 0;
    rf(i, 1, n) cin >> a[i];
    sol(1, 1);
    cout << f[1][1];
    return 0;
}