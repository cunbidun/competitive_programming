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

int n,m,num[MAXA],a[MAXA];
vi adj[MAXA];
vi ans;
void dfs(int u) {
    //cout << u << endl;
    ans.pb(u);
    num[u]++;
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        num[v]++;
        if(num[v] == a[v]) {
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i, 1, m) {int u, v; cin >> u >> v, adj[u].pb(v), adj[v].pb(u);}
    rf(i, 1, n) cin >> a[i];
    rf(i, 1, n) {
        if(num[i] == a[i]) dfs(i);
    }
    cout << ans.size() << endl;
    rf(i, 0, (int)ans.size() - 1) cout << ans[i] << " ";
    return 0;
}