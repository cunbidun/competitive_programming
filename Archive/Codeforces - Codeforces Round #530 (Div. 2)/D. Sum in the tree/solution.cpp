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


int n;
int val[MAXA], ans[MAXA], lvl[MAXA], p[MAXA];
vi adj[MAXA];

void dfs(int u) {
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i];
        if(!lvl[v]) {
            lvl[v] = lvl[u] + 1;
            p[v] = u;
            dfs(v);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    cin >> n;
    rf(i, 2, n) {
        int temp;
        cin >> temp;
        adj[temp].pb(i);
    }
    lvl[1] = 1;
    dfs(1);
    rf(i, 1, n) {
        cin >> val[i];
        ans [i] = INF;
    }
    rf(i, 1, n) {
        if(val[i] == -1) {
            if((int)adj[i].size()) {
               // cout << i << endl;
                int temp = val[p[i]];
                rf(j, 0, (int)adj[i].size() - 1) {
             //       cout << adj[i][j] << endl;
                    ans[i] = min(ans[i], val[adj[i][j]] - temp);
                }
            }
            else ans[i] = 0;
            if(ans[i] < 0) if(ans [i] < 0) return cout << -1, 0;
            val[i] = ans[i] + val[p[i]];
            //cout << i << " " << ans[i] << endl;
        }

    }
   // watch(n);

    ans[1] = val[1];
    rf(i, 2, n) {
        if(ans[i] != INF) continue;
        ans[i] = val[i] - val[p[i]];
        if(ans [i] < 0) return cout << -1, 0;
    }
    ll fin = 0;
    rf(i, 1, n) fin += 1LL * ans[i];
    cout << fin;
    return 0;
}