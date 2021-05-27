#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define endl "\n"
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
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n,m;
vi ans, adj[MAXA], num[MAXA];
int lvl[MAXA];
bool vis[MAXA];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
     // freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i,1,m){
        int u,v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    priority_queue<int, vector<int>, greater<int>>q;
    q.push(1);
    vis[1] = 1;
    while(!q.empty()) {
        int u = q.top();
        q.pop();
        cout << u << " ";

        rf(i,0,(int)adj[u].size() - 1) {
            if(!vis[adj[u][i]]) {
                vis[adj[u][i]] = 1;
                q.push(adj[u][i]);
            }
        }
    }
    return 0;
}