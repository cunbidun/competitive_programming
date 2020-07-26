#include <bits/stdc++.h>

using namespace std;

#define ll unsigned long long
#define pb push_back
#define F first
#define S second
#define rf(i,a,b) for(int (i) = (a); (i) <= (b); (i)++)
#define rb(i,b,a) for(int (i) = (b); (i) >= (a); (i)--)
#define watch(x) cout << (#x) << " = " << (x) << endl
#define reset(a,b) memset((a),(b),sizeof(a))
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    test(t) {
        ll l, r;
        int mx = 0;
        ll ans = 0;
        cin >> l >> r;
        ans = r;
        mx =  __builtin_popcountll(r);
        for(ll i = 0; (1LL << i) <= r; i++) {
            if((r >> i) & 1LL) {
                ll rr = r;
                rr |= ((1LL << i) - 1LL);
                rr ^= (1LL << i);
                if(rr >= l) {
                    int temp =  __builtin_popcountll(rr);
                     if(temp >= mx) {
                        ans = rr;
                        mx = temp;
                     }
                }
                else break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}