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
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;
    
using namespace std;
    
typedef pair<int, int> ii;
typedef pair<ll, int> li;
typedef pair<ll, ii> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, p[MAXA], lvl[MAXA];
vector<II> edgeList;
li a[MAXA];
ll ans = 0;
int findSet(int u) {
    return (u == p[u]) ? u : (p[u] = findSet(p[u]));
}
bool isSameSet(int u, int v) {
    return (findSet(u) == findSet(v));
}   
void mergeSet(int u, int v) {
    if(!isSameSet(u,v)) {
        u = findSet(u);
        v = findSet(v);
        if(lvl[u] > lvl[v]) p[v] = u;
        else {
            p[u] = v;
            if(lvl[u] == lvl[v]) lvl[v] ++;
        }
    }
}                  
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL); 
    //clock_t clk = clock();
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        p[i] = i;
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + n + 1);
    for(int i = 2; i <= n; i++) {
        edgeList.pb(II(a[i].first + a[1].first, ii(a[i].second, a[1].second)));
        //cout << a[i].first + a[1].first << " " << a[i].second << " " << a[1].second << endl;
    }
    for(int i = 1; i <= m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        //cout << w << " " << u << " " << v << endl;
        edgeList.pb(II(w,ii(u,v)));
    }
    sort(edgeList.begin(), edgeList.end());
    for(int i = 0; i < edgeList.size(); i++) {
        int u = edgeList[i].second.first;
        int v = edgeList[i].second.second;
        ll w = edgeList[i].first;
        if(!isSameSet(u,v)) {
            mergeSet(u,v);
            ans += 1LL*w;
        }
    }
    cout << ans << endl;
    //cerr << "Time (in ms): " << double(clock() - clk) * 1000.0 / CLOCKS_PER_SEC << '\n';
    return 0;
}