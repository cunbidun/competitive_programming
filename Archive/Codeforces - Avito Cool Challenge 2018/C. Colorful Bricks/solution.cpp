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
const int MAXA = 2e3 + 10;
const int MOD = 998244353;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k;
ll f[MAXA][MAXA];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m >> k;
    k++;
    rf(i, 1, n) f[i][1] = 1LL;
    rf(i, 2, n)
        rf(j, 1, k){
            f[i][j] = (f[i - 1][j - 1] + f[i - 1][j]) % MOD;
    }
    ll ans = 1LL * m;
    rf(i,2,k) {
        ans = (ans * 1LL * (m - 1)) % MOD;
    }
    cout << (ans *f[n][k]) % MOD;
    return 0;
}