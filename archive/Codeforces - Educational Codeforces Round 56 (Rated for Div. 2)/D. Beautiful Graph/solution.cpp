#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>

#define ll long long
#define pb push_back    
#define watch(x) cout << (#x) << " = " << (x) << endl

const int INF = 1e9 + 7;
const int MAXA = 3e5 + 10;
const int MOD = 998244353;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, t, cnt1, cnt2, cnt0;
int lvl[MAXA];
bool visited[MAXA], ok = 1;
vector<vi> adjList;

ll powMod (int a, int b) {
    //cout << a << endl;
    if (b == 0) return 1LL;
    if (b % 2 == 0) return powMod((1LL * a * a) % MOD, b / 2);
    else return (1LL * a * powMod(a,b - 1)) % MOD;
}

bool dfs(int u) {
    //watch(u);
    visited[u] = 1;
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(!visited[v]) {
            lvl[v] = lvl[u] + 1;
            if(lvl[v] % 2 == 1) cnt1 ++;
            else cnt2++;
            dfs(v);
        }
        else {
            if(lvl[v] % 2 == lvl[u] % 2) {
                // cout << u << "  " << v << endl;
                // cout << "!!!" << endl;
                ok = 0;
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> t;
    while(t --) {
        cin >> n >> m;
        if(n == 1) {
            cout << 3 << endl;
            continue;
        }
        memset(visited,0, n+2);
        memset(lvl,0, n+2);
        cnt1 = 0, cnt2 = 0, cnt0 = 0;
        ll ans = 1LL;
        adjList.assign(n + 5, vi());
        for(int i = 1; i <= m; i ++) {
            int u, v;
            cin >> u >> v;
            adjList[u].pb(v);
            adjList[v].pb(u);
        }
        
        ok = 1;
        for(int i = 1; i <= n; i++) {
            if(adjList[i].size() == 0) cnt0++;
            else {
                if(!visited[i]) {
                    lvl[i] = 1;
                    cnt1 = cnt2 = 0;
                    cnt1++;
                    ok = 1;
                    dfs(i);
                    if(!ok) {
                        cout << 0 << endl;
                        break;
                    }
                    //watch(cnt2);
                    ans = (ans * (powMod(2,cnt1) + powMod(2,cnt2)) % MOD) % MOD;
                }
            }
        }

        if(ok) cout << (ans * powMod(3,cnt0)) % MOD << endl;

    }
    return 0;
}