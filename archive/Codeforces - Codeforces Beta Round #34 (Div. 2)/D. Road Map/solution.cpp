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
const int MAXA = 5e4 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;
const double PI = 3.14159265358979323846264;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, p[MAXA], r1,r2;
vi adj[MAXA];

void dfs(int u, int l) {
    rf(i, 0, (int)adj[u].size() - 1) {
        int v= adj[u][i];
        if(v!= l) {
            p[v] = u;
            dfs(v,u);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
#endif
    cin >> n >> r1 >> r2;
    for(int i = 1; i <= n - 1; i ++) {
        int u;
        cin >> u;
        if(i < r1) {
            adj[u].pb(i);
            adj[i].pb(u);
        } else {
            adj[u].pb(i + 1);
            adj[i + 1].pb(u);
        }
    }
    dfs(r2,r2);
    for(int i= 1; i <= n; i++) {
        if(i != r2) {
            cout << p[i] <<  " ";
        }
    }
    return 0;
}