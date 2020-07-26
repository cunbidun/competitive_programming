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

typedef pair<ll, ll> ii;
typedef pair<ii, ll> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, k;
II a[MAXA];
vii ch[350];
ll f[350][350], pre[350][350];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m >> k;
    rf(i,1,n) {
        rf(j,1,n) {
            f[i][j] = INFLL;
            pre[i][j] = INFLL;
        }
    }
    rf(i,1,m) {
        cin >> a[i].F.F  >> a[i].F.S >> a[i].S;
        pre[a[i].F.F][a[i].F.S] = min(pre[a[i].F.F][a[i].F.S],a[i].S);
    }
    rf(i,1,n) rb(j, n - 1, i) pre[i][j] = min(pre[i][j],pre[i][j + 1]);
//    sort(a + 1, a + 1 + m);
//    rf(i,1,n) {
//        rf(j, 1, m) {
//            int st = a[j].F.F, en = a[j].F.S;
//            ll cost = a[j].S;
//            if(i < st)
//                pre[i][en] = min(pre[i][en], pre[i][st - 1] + cost);
//            else if (i <= en)
//                pre[i][en] = min(pre[i][en], cost);
//        }
//        rb(j, n - 1, i) pre[i][j] = min(pre[i][j],pre[i][j + 1]);
//    }
//
//    rf(j,1,n) rf(i,2,j) {
//        pre[i][j] = min(pre[i][j],pre[i-1][j]);
//    }

    rf(i,0,n) f[i][0] = 0LL;

    rf(i,1,n) {
        rf(j,0,k) {
            rf(l,1,i)
                f[i][j] = min(f[i][j], f[l][j]);
            rf(l,1,i) if(j >= (i - l + 1) && pre[l][i] != INFLL && l - 1 >= j - (i - l + 1)){
                f[i][j] = min(f[i][j], f[l - 1][j - (i - l + 1)] + pre[l][i]);
            }
        }
    }

    if(f[n][k] == INFLL) cout << -1;
    else cout << f[n][k] ;
    return 0;
}