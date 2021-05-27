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

int n, ans[MAXA];
ii a[MAXA];
int BIT[MAXA];
void update(int x, int val) {
	while(x > 0) {
		BIT[x] += val;
		x -= x & -x;
	}
}		
int getSum(int x) {
	int ans = 0;
	while(x <= n) {
		ans += BIT[x];
		x += x & -x;
	}
	return ans;
}
bool cmp(ii A, ii B) {
	if(A.F != B.F) return A.F < B.F;
	if(A.S != B.S) return A.S < B.S;
}
int main() {
    #ifndef ONLINE_JUDGE
    // freopen("in.in", "r", stdin);
    //freopen("out.out", "w", stdout);
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin >> n;
    rep(i, 1, n) {
    	cin >> a[i].F;
    	a[i].S = i;
    }
    sort(a + 1, a + n + 1, cmp);
    int last = 0;
    rep(i, 1, n) {
    	int temp = getSum(a[i].S);
    	if(!temp) {
    		if(last) update(last, -last);
    		last = a[i].S;
			ans[a[i].S] = -1;
    		update(a[i].S,a[i].S);
    	}
	    else 
	    	ans[a[i].S] = temp - a[i].S - 1;
    }
    rep(i, 1, n) cout << ans[i] << " ";
    return 0;  
}