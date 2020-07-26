#include <bits/stdc++.h>

using namespace std;
	
#define ll long long
#define pb push_back  
#define F first
#define S second
#define rep(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)  
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;							
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    clock_t clk = clock();
    #endif

    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
   	cin >> n >> m;
   	if(n > log2(1000000000)) {
   		cout << m;
   	}
   	else cout << m % (1 << n);
    #ifndef ONLINE_JUDGE
    //cout << endl << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    #endif
    
    return 0;
}