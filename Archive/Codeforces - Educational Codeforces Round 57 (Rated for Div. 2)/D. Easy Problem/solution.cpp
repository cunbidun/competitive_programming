#include <bits/stdc++.h>

using namespace std;
    
#define ll long long
#define pb push_back  
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

    
const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
        
int n, a[MAXA];
ll f[MAXA][5];
string S, H = "hard";

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios::sync_with_stdio(0); cin.tie(0); 
    
    cin >> n;
    cin >> S;
    S = '^' + S;
    rep(i,1,n) cin >> a[i];
    rep(j,0,3) 
        rep(i,1,n)
            f[i][j] = INFLL;
    f[0][0] = 0; 
    rep(j,0,3) {
        rep(i,1,n) {
            if(S[i] != H[j]) f[i][j] = f[i - 1][j];
            else {
                if(j)
                f[i][j] = min(f[i - 1][j] + 1LL * a[i], f[i - 1][j - 1]);
                else{
                    f[i][j] = f[i - 1][j] + 1LL * a[i];
                }
            }
        }
    }    
    cout << min({f[n][0], f[n][1], f[n][2], f[n][3]});

    #ifndef ONLINE_JUDGE
    cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}