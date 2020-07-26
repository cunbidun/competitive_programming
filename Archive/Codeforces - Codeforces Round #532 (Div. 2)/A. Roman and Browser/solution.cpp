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

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, ans, k , a[140], so ,t;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    rf(i,1 , n) {
        cin >> a[i];
        if(a[i] == 1) t ++;
        else so ++;
    }
     rf(i, 1, n) {
        int e = 0, s =0;
        rf(j, 1, n) {
            if(j % k == i % k) {
                if(a[j] == 1) s ++;
                else e ++;
            }
        }
        ans = max(ans, abs((t - s) - (so - e)));
    }
    cout << ans;
    return 0;
}