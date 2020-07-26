/*input
2 1 4
1 5 3
3 3 10
7 10 2
6 4 8
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

int n, t, m, L, A, B;					

bool check(int x) {
	if(t < A + (x - 1) * B) return 0;
	x = x - L + 1;
	ll firstNum = A + 1LL * (L - 1) * B;
	ll sum = firstNum * x;
	sum += 1LL * x * (x - 1) / 2 * 1LL * B; 
	if (sum > 1LL * t * m) return 0;
	return 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> A >> B >> n;
    rep(i, 1, n) {
    	int l;
    	cin >> l >> t >> m;
    	if(t < 1LL * A + 1LL * (l - 1) * B) {cout << -1 << endl; continue;}
    	L = l;
    	int r = 1e7;
    	while(l != r) {
    		if(l + 1 == r) {
    			if(check(r)) l = r;
    			else r = l;
    		}
    		int mid = (l + r) >> 1;
    		if (check(mid)) {
    			l = mid;
    		}
    		else r = mid - 1;
    	}
    	if(L <= l ) cout << l << endl;
    	else cout << -1 << endl;
    }
    return 0;  
}