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
typedef pair<ii, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, m, pos[MAXA];
vii adj[MAXA];
vi ts, ans;
vector<iii> edgeList;
bool ch, visited[MAXA], finished[MAXA];

void dfs(int u, int cur) {
    visited[u] = 1;
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i].F;
        int c = adj[u][i].S;
        if(!visited[v] && c > cur) dfs(v, cur);
        else if(!finished[v] && c > cur ) {
            ch = 0;
            return;
        }
    }
    finished[u] = 1;
}

bool check(int mid) {
    rf(i,1,n) visited[i] = 0, finished[i] = 0;
    rf(i,1,n) {
        if(!visited[i]) {
            ch = 1;
            dfs(i, mid);
            if(!ch) return 0;
        }
    }
    return 1;
}

void dfsTopo(int u, int cur) {
    visited[u] = 1;
    rf(i, 0, (int)adj[u].size() - 1) {
        int v = adj[u][i].F;
        int c = adj[u][i].S;
        if(!visited[v] && c > cur) dfsTopo(v, cur);
    }
    ts.pb(u);
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
       freopen("in.in", "r", stdin);
    #endif
    cin >> n >> m;
    rf(i, 1, m) {
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].pb(ii(v, c));
        edgeList.pb(iii(ii(c,i),ii(u,v)));
    }
//    cout << check(523) << endl;
//    rf(i,1,n)cout << visited[i] << " "; cout << endl;
    int l = 0, r = 1e9;
    while(l < r) {
        if (l == r - 1) {
            if(check(l)) r = l;
            else l = r;
        }
        int mid = (l + r) >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << " ";
    rf(i,1,n) visited[i] = 0;
    rf(i,1,n) {
        if(!visited[i]) dfsTopo(i, l);
    }
    reverse(ts.begin(), ts.end());
   //rf(i,0,(int)ts.size() - 1) cout << ts[i] <<  " "; cout << endl;
    sort(edgeList.begin(),edgeList.end());
    rf(i, 0, (int)ts.size() - 1) pos[ts[i]] = i;
    rf(i, 0, (int)edgeList.size() - 1) {
        if(edgeList[i].F.F > l) break;
        int u = edgeList[i].S.F;
        int v = edgeList[i].S.S;
     //   cout << u << " " << v << endl;
        if(pos[u] > pos[v]) ans.pb(edgeList[i].F.S);
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    rf(i, 0 , (int) ans.size() - 1) cout << ans[i] << " ";
    return 0;
}