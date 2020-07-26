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
#define test(t) int(testCnt) = 0; int(t); cin >> (t); while(t -- && ++testCnt)

const int INF = 2e9 + 7;
const int MAXA = 1e5 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

vi adjList[MAXA];
int n, m, val[MAXA];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       // freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i, 1, m) {
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    rf(i, 1, n) val[i] = 1;
    ll ans = 0LL;
    rf(i, 1, n) {
        ans = max(ans, 1LL * (int)adjList[i].size() * 1LL * val[i]);
        rf(j, 0, (int)adjList[i].size() - 1) {
            int next = adjList[i][j];
            if(next > i) {
                val[next] = max(val[next], val[i] + 1);
            }
        }
    }
    cout << ans;
    return 0;
}