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
const int MAXA = 1e3 + 10;
const int MOD = 1e9 + 7;

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ll> il;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, mx = -1, Next = -1, pos, ansSt = -1, ansNd = -1;
int lvl[MAXA], p[MAXA][12];
bool visited[MAXA];
vi adjList[MAXA];
vii midList;
int dfs(int u) {
    visited[u] = 1;
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(!visited[v]) {
            lvl[v] = lvl[u] + 1;
            if(lvl[v] > mx) {
                mx = lvl[v];
                Next = v;
            }
            dfs(v);
        }
    }
    return Next;
}

int dfsFind(int u, int l) {
    for(int i = 0; i < adjList[u].size(); i++) {
        int v = adjList[u][i];
        if(v != l) {
            p[v][0] = u;
            lvl[v] = lvl[u] + 1;
            if(lvl[v] > mx) {
                mx = lvl[v];
                pos = v; 
            }
            dfsFind(v, u);
        }
    }
    return pos;
}

int findMid(int u, int step) {
    for(int i = 10; i >= 0; i --) {
        if(step >= (1 << i)) {
            u = p[u][i];
            step -= (1 << i);
        }
    }
    return u;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    #endif
    ios::sync_with_stdio(false);
    cin >> n >> m;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    for(int i = 1; i <= m; i ++) {
        int u, v;
        cin >> u >> v;
        adjList[u].pb(v);
        adjList[v].pb(u);
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            mx = 0;
            Next = i;
            int temp = dfs(i);
            //watch(i);
            //watch(temp);
            mx = 0;
            pos = temp;
            lvl[pos] = 1;
            dfsFind(temp,temp);
            //watch(pos);
            //watch(mx);
            for(int j = 1; j <= 10; j ++) {
                for(int i = 1; i <= n; i++) {
                    p[i][j] = p[p[i][j - 1]][j - 1];
                }
            }
            int mid = findMid(pos, mx / 2);
            //watch(mid);
            midList.pb(ii(mx / 2, mid));
            if(m == n - 1) {
                cout << mx - 1 << endl;
                return 0;
            }
        }
    }  
   
    sort(midList.begin(), midList.end());
    // for(int i = midList.size() - 1; i >= 0; i--) {
    //     cout << midList[i].second << " " << midList[i].first << endl;
    // }
    for(int i = midList.size() - 2; i >= 0; i--) {
        adjList[midList[midList.size() - 1].second].pb(midList[i].second);
        adjList[midList[i].second].pb(midList[midList.size() - 1].second);
    }
    for(int i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    mx = 0;
    Next = 1;
    int temp = dfs(1);
    //watch(temp);
    mx = 0;
    pos = temp;
    lvl[pos] = 1;
    dfsFind(temp,temp);
    cout << mx - 1 << endl;
    for(int i = midList.size() - 2; i >= 0; i--) {
        cout << midList[midList.size() - 1].second << " " << midList[i].second << endl;
    }
}