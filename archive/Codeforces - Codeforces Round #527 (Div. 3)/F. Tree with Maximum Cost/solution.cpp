#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 2e5 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, pos, a[MAXA], lvl[MAXA];
ll ans = 1, totalDis[MAXA], S, sumChild[MAXA];
vi adjList[MAXA];

void dfs(int u, int l) {
    sumChild[u] = a[u];
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(v != l) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            sumChild[u] += sumChild[v];
        }
    }
}

void dfsSolve(int u, int l) {
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(v != l) {
            totalDis[v] = totalDis[u] - sumChild[v] + S - sumChild[v];
            if(ans < totalDis[v]) {
                ans = totalDis[v];
                pos = v;
            }
            dfsSolve(v, u);
        }
    }
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        S += a[i];
    }
    for(int i = 1; i <= n - 1; i ++) {
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }
    dfs(1,1);
    
    for(int i = 2; i <= n; i++) {
        totalDis[1] += 1LL * lvl[i] * a[i];
    }
    ans = totalDis[1];
    //watch(ans);
    dfsSolve(1, 1);
    //for(int i = 1; i <= n; i++) {
        //watch(i); 
        //watch(totalDis[i]);
    //}
    //watch(pos);
    cout << ans;
    return 0;
}