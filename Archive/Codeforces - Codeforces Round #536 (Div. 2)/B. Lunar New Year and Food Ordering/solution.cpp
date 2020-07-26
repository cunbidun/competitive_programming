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
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<ll, ll> ii;
typedef pair<ii, ll> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m;
ll c[MAXA];
II a[MAXA];
int pos[MAXA];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
#endif
    cin >> n >> m;
    rf(i,1,n) cin >> a[i].F.S,a[i].S = i;
    rf(i,1,n) cin >> a[i].F.F;
    sort(a + 1,a + n + 1);
    rf(i,1,n) {
        pos[a[i].S] = i;
    }
    int cur = 1;
    bool f = 0;
    rf(i,1,m) {
        if(f) {
            cout << 0 << endl;
            continue;
        }
        ll t,d;
        cin >> t >> d;
        ll ans = 0;
        ll tmp = min(d,a[pos[t]].F.S);
        ans +=  tmp * a[pos[t]].F.F;
        d -= tmp;
        a[pos[t]].F.S -= tmp;
      //  watch(i);
        //cout << tmp << endl;
        while(d) {
            ll tmp = min(d,a[cur].F.S);
            ans += tmp * a[cur].F.F;
           // cout << tmp << " "  << tmp * a[cur].F.F << endl;
            d -=  tmp;
            a[cur].F.S -= tmp;
            if(!d)break;
            while(a[cur].F.S == 0) {
                cur ++;
                if(cur > n) {
                    f = 1;
                    break;
                }
            }
            if(f) {
                cout << 0 << endl;
                break;
            }
        }
        if(!f)
            cout << ans << endl;
    }
    return 0;
}