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

const int INF = 2e9 + 7;
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,m;
vi adjList[MAXA];
int num[MAXA];
bool visited[MAXA];
int ans = 0;
bool ok;
void dfs(int u) {
    visited[u] = 1;
    rf(i,0,(int)adjList[u].size() - 1) {
        int v = adjList[u][i];
        if (ok) return;
        if(!visited[v]) {
            num[v] = 1 - num[u];
            dfs(v);
        }
        else {
            if (num[v] == num[u]) {
                ans ++;
                ok = 1;
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i,1,m) {
        int u, v;
        cin >> u >> v;
        adjList[v].pb(u);
        adjList[u].pb(v);
    }
    num[1] = 1;
    rf(i, 1, n) {
        if(!visited[i]) {
            ok = 0;
            dfs(i);
        }
    }
    if((n - ans) % 2 == 0)
    cout << ans;
    else cout << ans + 1;
    return 0;
}