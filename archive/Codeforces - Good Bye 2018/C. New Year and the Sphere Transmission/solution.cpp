#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(ll (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) ll(testCnt) = 0; ll(t); cin >> (t); while(t -- && ++testCnt) 

const ll INF = 2e9 + 7;
const ll MAXA = 1e5 + 10;
const ll MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<ll, ll> ii;
typedef pair<ii, ll> II;
typedef vector<ll> vi;
typedef vector<ii> vii;
ll n;
vi ans;
ll cal(ll dis) {
    ll ans = 0;
    ll temp = (n + 1 + 1) * (n / dis + 1) / 2 - n - 1;
    return temp;
}              

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios::sync_with_stdio(0); cin.tie(0); 
    
    cin >> n ;
    rep(i,1,sqrt(n)){
        if(n % i == 0) {
            ans.push_back(cal(i));
            ans.push_back(cal(n/i));
        }
    }

    sort(ans.begin(), ans.end());
    ans.erase( unique( ans.begin(), ans.end() ), ans.end() );
    rep(i,0,ans.size() - 1) cout << ans[i] << " ";

    #ifndef ONLINE_JUDGE
    cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}