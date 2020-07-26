#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

    
const int INF = 2e9 + 7;
const int MAXA = 1e6 + 10;
const ll MOD = 998244353;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll f[MAXA];
int n;
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios::sync_with_stdio(0); cin.tie(0); 
    
    f[0] = 0LL;
    f[1] = 0LL;
    cin >> n;
    rep(i,2,n) {
        f[i] = 1LL * i * (f[i-1] + 1LL);
        f[i] %= MOD; 
    }

    ll mul = 1LL;
    rep(i,2,n) {
        mul = (mul * 1LL * i) % MOD;
    }

    mul = (mul * n) % MOD;
    cout << (MOD + mul - f[n]) % MOD;
    #ifndef ONLINE_JUDGE
    cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}