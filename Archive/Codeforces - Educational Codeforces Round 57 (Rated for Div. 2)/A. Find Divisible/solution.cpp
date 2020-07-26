#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
                                
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); 
    clock_t clk = clock();
    int t;
    cin >> t;
    while(t --) {
        int l,r ;
        cin >> l >> r;
        cout << l << " " << l * 2 << endl;
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}