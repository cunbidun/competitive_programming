#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cmath>
#include <ctime>
    
#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl
    
const int INF = 2e9 + 7;
const int MAXA = 3e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA];
ll mx = 0;
vii adjList[MAXA];

ll dfs(int u, int l) {
    ll m1 = 0, m2 = 0;
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i].first;
        int w = adjList[u][i].second;
        if(v != l) {
            ll temp = dfs(v, u);
            temp -= w;
          //  cout << u << " " << v << " " << temp << endl;
            if(temp >= m1) {
                m2 = m1;
                m1 = temp;
            }
            else if(temp >= m2) {
                m2 = temp;
            }
        }
    }
    mx = max(mx, m1 + m2 + 1LL * a[u]);
    return m1 + 1LL * a[u];
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    clock_t clk = clock();
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adjList[u].pb({v,w});
        adjList[v].pb({u,w});
    }    
    dfs(1,1);
    cout << mx << endl;
    cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}