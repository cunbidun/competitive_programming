#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

int n, m, t;
vii a[5001];
vii p[5001];
bool vis[5001];
int f[5001][5001];
vi l;

void topologicalSort(int u) {
    vis[u] = 1;
    for (ii v : a[u])
        if (!vis[v.first])
            topologicalSort(v.first);
    l.pb(u);
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> t;
    rf(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v, w});
        p[v].pb({u, w});
    }
    rf(i, 1, n) rf(j, 1, n) f[i][j] = 2e9;
    topologicalSort(1);
    reverse(all(l));
    f[1][1] = 0;
    for (int v : l) {
        for (ii u : p[v]) {
            rf(i, 1, n - 1) if (1ll * f[u.first][i] + u.second <= t) f[v][i + 1] = min(f[v][i + 1], f[u.first][i] + u.second);
        }
    }
    vi ans;
    int u = n;
    ll cost = 0;
    int num = 0;
    rb(i, n, 2) if (f[n][i] <= t) {
        cout << i << "\n";
        num = i;
        cost = f[n][i];
        break;
    }
    ans.pb(n);
    while (u != 1) {
        for (ii l : p[u]) {
            if (f[l.first][num - 1] == cost - l.second) {
                ans.pb(l.first);
                cost -= l.second;
                u = l.first;
                break;
            }
        }
        num--;
    }
    for (int i = sz(ans) - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}