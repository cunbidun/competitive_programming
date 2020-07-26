#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,k, a[MAXA];
vi pos[MAXA];
string s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
//    freopen("in.in", "r", stdin);
#endif
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    cin >> s;
    s = "*" + s;
    int cur = 0;
    rf(i,1,n) {
        if(s[i] == s[i - 1]) {
            //watch(cur);
            pos[cur].pb(a[i]);
        } else {
          //  cout << endl;
            cur ++;
            pos[cur].pb(a[i]);
        }
    }
    ll ans = 0;
    rf(i,1,cur) {
        sort(pos[i].begin(),pos[i].end(), greater<int>());
    }
    rf(i,1,cur) {
        int tmp = min(k,(int)pos[i].size());
        rf(j,0,tmp - 1) {
            ans += 1LL * pos[i][j];
        }
    }
    cout << ans;
    return 0;
}