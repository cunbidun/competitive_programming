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
const int MAXA = 1e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const int lim = 2259990;

typedef pair<ll, ll> ii;
typedef pair<ii, int> II;
typedef vector<ll> vi;
typedef vector<ii> vii;

ll sqSum(int x) {
    x--;
    return 1LL * (x) * (x + 1) / 2 * ( - x - 2) / 3;
}

vii ans;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
      //  freopen("in.in", "r", stdin);
    #endif
    ll Q;
    cin >> Q;

    rf(i, 1, lim) {
        if(i * i > Q) break;

        ll temp = sqSum(i);
        ll tempy = 1LL * i * (i + 1) / 2;

        if((Q - temp) % tempy == 0) {
            ll res = (Q - temp) / tempy;
            if(res >= i)
                ans.pb(ii(i,(Q - temp) / tempy));
        }
    }

    int temp = ans.size();
    rf(i, 0, temp - 1) ans.pb(ii(ans[i].S, ans[i].F));
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    cout << ans.size() << endl;
    rf(i,0, (int)ans.size() - 1) cout<< ans[i].F << " " << ans[i].S << endl;
    return 0;
}