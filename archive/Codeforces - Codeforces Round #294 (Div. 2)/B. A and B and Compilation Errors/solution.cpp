/*input
5
1 5 8 123 7
123 7 5 1
5 1 7

*/
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

int n, a[MAXA];
map <int, int> cntF, cntS, cntL;	
ii ans;

int main() {
    #ifndef ONLINE_JUDGE
    // freopen("in.in", "r", stdin);
    // freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) {cin >> a[i]; cntF[a[i]] ++; }
 	int temp;
    rep(i, 1, n - 1) {cin >> temp; cntS[temp] ++; }
    rep(i, 1, n - 2) {cin >> temp; cntL[temp] ++; }
    rep(i, 1, n) {
    	if(cntF[a[i]] != cntS[a[i]]) {
    		ans.F = a[i];
    	}
    	 if(cntS[a[i]] != cntL[a[i]]) 
    		ans.S = a[i];
    }
    cout << ans.F << " " << ans.S << endl;
    return 0;  
}