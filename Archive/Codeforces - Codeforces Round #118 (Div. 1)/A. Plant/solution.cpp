#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define reset(a,b) memset((a),(b),sizeof(a))

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll powMod (ll b) {
    if(b == 1) return 2LL;
    if(b == 0) return 1LL;
    ll t = powMod(b/2);
    return ((t * t) % MOD) * powMod(b % 2) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
    #endif
    ll n;
    cin >> n;

    if(n == 0) return cout << 1, 0;
    cout << (powMod(2*n - 1) + powMod(n - 1)) % MOD;

    return 0;
}