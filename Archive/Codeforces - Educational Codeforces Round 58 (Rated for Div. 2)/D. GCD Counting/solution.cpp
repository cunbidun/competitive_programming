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
const int MAXA = 2e5 + 10;
const ll MOD = (ll) 1e9 + 7;
const ll INFLL = 9e18 + 7;

typedef pair<int, int> ii;
typedef pair<ii, int> II;
typedef vector<int> vi;
typedef vector<ii> vii;

int n, a[MAXA];
bool isPrime[MAXA], visited[MAXA];
vi primeList;
vi adj[MAXA];
int ans = 0;
void sieve() {
    rf(i, 2, 200000) isPrime[i] = 1;
    rf(i, 2, 200000) {
        if(!isPrime[i]) continue;
        primeList.pb(i);
        for(int j = i * 2; j <= 200000/i; j += i){
            isPrime[j] = 0;
        }

    }
}
int dfs(int u, int num) {
    visited[u] = 1;
    if(a[u] % num != 0) return 0;
    int mx1 = 0, mx2 = 0;
    rf(i,0,(int)adj[u].size() - 1) {
        int v = adj[u][i];
        if(!visited[v] && a[v] % num == 0) {
            int t = dfs(v, num);
            if(t >= mx1) mx2 = mx1, mx1 = t;
            else if(t > mx2) mx2 = t;
        }
    }
    ans = max(ans, mx1 + mx2 + 1);
    return mx1 + 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        //freopen("in.in", "r", stdin);
    #endif
    sieve();
    cin >> n;
    rf(i,1,n) cin >> a[i];
    rf(i,1,n - 1) {
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    //cout << dfs(1,2) <<endl;
    rf(i, 0, (int)primeList.size() - 1) {
        if(primeList[i] * primeList[i] > 200000) break;
        memset(visited, 0, sizeof(visited));
        rf(j, 1, n) if(!visited[j]){
            //if(primeList[i] ==2) cout << j << endl;
            dfs(j,primeList[i]);
        }
    }
    memset(visited, 0, sizeof(visited));
    rf(i, 1, n) {
        if(isPrime[a[i]] && !visited[i]){
            dfs(i,a[i]);
        }
    }
    cout << ans;
    return 0;
}