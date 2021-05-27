#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 998244353;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

string S;
int n;                              
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif
    ios::sync_with_stdio(0); cin.tie(0); 
    clock_t clk = clock();
    cin >> n;
    cin >> S;
    S = '*' + S;
    int cntS = 1;
    for(int i = 2; i <= n; i++) {
        if(S[i] == S[i - 1]) {
           cntS ++; 
        }
        else break;
    }
    int cntE = 1;
    for(int i = n - 1; i >= 1; i--) {
        if(S[i] == S[i + 1]) {
           cntE ++; 
        }
        else break;
    }

    if(S[1] == S[n]) {
        cout << 1LL * (cntE + 1) * (cntS + 1) % MOD;
    }
    else {
        cout << cntE + cntS + 1;
    }
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}