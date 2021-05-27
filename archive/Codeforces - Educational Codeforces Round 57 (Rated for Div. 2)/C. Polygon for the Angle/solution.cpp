#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 182 + 10;
const int MOD = 998244353;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
vi ans[MAXA];
int n;                              
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); 
    clock_t clk = clock();
    for(int i = 3; i <= 180; i++) {
        for(int j = 1; j <= i - 2; j ++) {
            if( (180 * j) % i == 0)
            ans[180 * j / i].pb(i);
        }
    }
    int t;
    cin >> t;
    while(t --) {
        cin >> n;
        if(n == 179) cout << 360 << endl;
        else 
        cout << ans[n][0] << endl;
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}