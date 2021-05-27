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

int n, sum[MAXA], mx[MAXA], mn[MAXA];
string S[MAXA];
int cnt[10 * MAXA];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) cin >> S[i];
    rf(i, 1, n) {
        rf(j, 0 , S[i].size() - 1) {
            if(S[i][j] == ')') {
                sum[i] --;
                mn[i] = min(mn[i],sum[i]);
            }
            else {
                sum[i] ++;
                mx[i] = max(mx[i],sum[i]);
            }
        }
        if(sum[i] == mn[i] || mn[i] == 0) {
           // cout << sum[i] << endl;
            cnt[sum[i] + 500000] ++;
        }
    }
    int ans = 0;
    rf(i, 0, 1000000) {
        if (i == 500000) {
            ans += cnt[i] / 2;
            continue;
        }
        int temp = min(cnt[i], cnt[1000000 - i]);
        ans += temp;
        //if(temp > 0) cout << i << endl;
        cnt[i] -= temp;
        cnt[1000000 - i] -= temp;
    }
    cout << ans;
    return 0;
}