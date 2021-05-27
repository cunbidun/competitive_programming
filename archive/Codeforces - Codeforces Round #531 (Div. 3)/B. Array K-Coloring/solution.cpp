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
const int MAXA = 5e3 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, k, ans[MAXA], cnt[MAXA], mx;
ii a[MAXA];
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> k;
    if(k > n) return cout << "NO", 0;
    rf(i, 1, n) {cin >> a[i].F, a[i].S = i, cnt[a[i].F] ++, mx = max(mx, cnt[a[i].F]);};
    sort(a + 1, a + n + 1);
    if(mx > k) return cout << "NO", 0;
    cout << "YES" << endl;
    int cur = 1;
    int nn = n;
    while(n) {
    //    cout << n << endl;
        rf(j, 1, k) {
            ans[a[cur].S] = j;
            cur++;
            n--;
            if(n == 0) break;
        }
    }
    rf(i, 1, nn) cout << ans[i] << " ";
    return 0;
}