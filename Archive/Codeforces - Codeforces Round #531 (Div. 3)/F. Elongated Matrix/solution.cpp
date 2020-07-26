#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define dp dpirst
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) < (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e4 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, a[18][MAXA], dp[1 << 18][18], mn1[18][18], mn2[18][18];

int calc(int mask, int v) {
	if(dp[mask][v] != -1) return dp[mask][v];
	dp[mask][v] = 0;
	rf(i, 0, n) {
		if(v != i && ((mask >> i) & 1)) {
			dp[mask][v] = max(dp[mask][v], min(calc(mask ^ (1 << v), i), mn1[i][v]));
		}
	}
	return dp[mask][v];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
       //freopen("in.in", "r", stdin);
    cin >> n >> m;

    rf(i, 0, n) rf(j, 0, m) cin >> a[i][j];
   	rf(i, 0, n)
    	rf(j, 0, n) {
    		int mn = INF;
    		rf(k, 0, m) mn = min(abs(a[i][k] - a[j][k]), mn);
    		mn1[j][i] = mn;
    		mn = INF;
    		rf(k, 0, m - 1) mn = min(abs(a[i][k] - a[j][k + 1]), mn);
    		mn2[i][j] = mn;
    	}
    int ans = 0;
    rf(i, 0, n) {
    	memset(dp, -1, sizeof(dp));
    	rf(j, 0, n) {
    		if(j == i) dp[1 << j][j] = INF;
    		//else dp[1 << j][j] = 0;

    	}
    	rf(j, 0, n) {
    		ans = max(ans, min(calc((1 << n) - 1, j), mn2[j][i]));
    		//cout << endl;
    	}
    }
    cout << ans;
    return 0;
}