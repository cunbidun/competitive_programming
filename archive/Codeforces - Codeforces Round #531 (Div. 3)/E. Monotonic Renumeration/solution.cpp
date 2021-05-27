#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt) 

const int INF = 2e9 + 7;
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 998244353;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,num[MAXA],fa[MAXA], la[MAXA], ele;
ii a[MAXA];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      	//freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
    	cin >> a[i].F;
    	a[i].S = i;
    }
    sort(a + 1, a + 1 + n); 
    rf(i, 1, n) {
    	fa[i] = INF;
    	if(a[i].F != a[i - 1].F)
    		num[a[i].S] = i;
    	else 
    		num[a[i].S] = num[a[i - 1].S];
    }
    rf(i, 1, n) {
    	fa[num[i]] = min(fa[num[i]], i);
    	la[num[i]] = max(la[num[i]], i);
    }
    // rf(i, 1, n) {
    // 	cout << fa[num[i]] << " " << la[num[i]] << endl;
    // }
    ll ans = 1LL;

    rf(i, 1, n) {
    	int mx = i;
    	//cout << la[num[i]] << endl;
    	int temp = i;
    	rf(j, temp, la[num[i]]) {
    		mx = max(mx, la[num[j]]);
    		i = max(mx, i);
    	}

	    //cout << i << endl;
	    ele ++;
	}
    rf(i, 1, ele - 1) {
    	ans = (2 * ans) % MOD;
    }
    cout << ans;
    return 0;
}