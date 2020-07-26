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
#define reset(a,v,b) rf(i, 0, b) a[i] = v

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m >> k;
    if(m == 1) return cout << 1, 0;
    if(k == 1) {
        ll ans = 1LL;
            rf(i, 1, n) {
            ans = (ans * 1LL * m) % MOD;
        }
        return cout << ans, 0;
    }
    if(n > k) {
        if(k % 2 == 0) {
            cout << m;
            return 0;
        }
        else {
            cout << m * (m);
        }
    }
    else {
        if(n < k) {
            ll ans = 1LL;
            rf(i, 1, n) {
                ans = (ans * 1LL * m) % MOD;
            }
            return cout << ans, 0;
        }
        else {
            ll ans = 1LL;
            if(n % 2 == 0) {
                    rf(i, 1, n/2) {
                    ans = (ans * 1LL * m) % MOD;
                }
                return cout << ans, 0;
            }
            else {
                rf(i, 1, n/2) {
                    ans = (ans * 1LL * m) % MOD;
                }
                ans = (ans * m) % MOD;
                return cout << ans, 0;
            }
        }
    }
    return 0;
}