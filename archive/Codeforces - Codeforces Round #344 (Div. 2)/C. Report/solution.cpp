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
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

vi numList, num, ans;
int  n, m, a[MAXA];
ii t[MAXA];
int mx = 0;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i, 1, n) cin >> a[i];
    rf(i, 1, m) {
        cin >> t[i].S >> t[i].F;
        mx = max(mx, t[i].F);
    }
    rf(i, 1, mx) num.pb(a[i]);
    int cur = t[m].F;
    numList.pb(m);
    rb(i, m - 1, 1) if(t[i].F > cur) {
        cur = t[i].F;
        numList.pb(i);
    }

    num.pb(-INF);
    sort(num.begin(), num.end());
    int r = mx, l = 1;
    rb(i, numList.size() - 2, 0) {
        rb(j, t[numList[i + 1]].F, t[numList[i]].F + 1) {
            a[j] = (t[numList[i+1]].S == 1) ? num[r--] : num[l++];
        }
    }
    rf(j, 1, t[numList[0]].F)
        a[j] = (t[numList[0]].S == 2) ? num[r--] : num[l++];
    rf(i, 1, n) cout << a[i] << " ";
    return 0;
}