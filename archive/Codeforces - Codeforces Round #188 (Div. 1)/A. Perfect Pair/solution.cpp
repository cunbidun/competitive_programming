#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define reset(a,b) memset((a),(b),sizeof(a))

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;
ll m, n, x;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      // freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m >> x;
    if(m >= x || n >= x) return cout << 0, 0;
    if(n <= 0 && m <= 0) {
        cout << -1;
        return 0;
    }
    if(m < n) swap(m,n);

    ll ans = 0LL;
    if(n < 0) {
        if(n % m == 0) {ans = abs(n/m); n = 0; }
        else {
            ans = abs(n / m) + 1;
            n = m + n % m;
        }
    }
    while(m < x && n < x) {
        if(m < n) {
            m = m + n;
        }
        else n = m + n;
        ans ++;
    }
    cout << ans;
    return 0;
}