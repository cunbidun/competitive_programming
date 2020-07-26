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
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

ll addMod(ll x, ll y) {return (x + y) % MOD;}

ll subMod(ll x, ll y) {return ((x - y) % MOD + MOD) % MOD;}

ll mulMod(ll x, ll y) {return ((x % MOD) * (y % MOD)) % MOD;}

ll powMod(ll x, ll p) {
    if (p == 0) return 1LL; if (p == 1) return x % MOD;
    ll t = powMod(x, (p/2));
    return (((t * t) % MOD) * powMod(x, p % 2)) % MOD;
}

ll revMod(ll x) {return powMod(x, MOD - 2);}

int nodeCnt, timeCnt, vis[MAXA];
int n;
vi adj[MAXA];
bool finished[MAXA];
ii res;

void dfs(int u) {
    vis[u] = ++timeCnt;
    nodeCnt ++;
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if(!vis[v]) dfs(v);
        else if(!finished[v]) {
            res = ii(1, vis[u] - vis[v] + 1);
        }
    }
    finished[u] = 1;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 1, n) {
        int child;
        cin >> child;
        adj[i].pb(child);
    }
    ll ans = 1LL;
    rf(i, 1, n) if(!vis[i]){
        nodeCnt = 0;
        timeCnt = 0;
        res = ii(0,0);
        dfs(i);
//        watch(nodeCnt);
//        watch(timeCnt);
//        watch(res.F);
//        watch(res.S);
        if(res.F == 1) {
            ans = mulMod(ans, powMod(2, nodeCnt - res.S));
            ll temp = subMod(powMod(2, res.S), 2);
            ans = mulMod(ans, temp);
        }
        else ans = mulMod(ans, powMod(2, nodeCnt));
    }
    cout << ans;
    return 0;
}