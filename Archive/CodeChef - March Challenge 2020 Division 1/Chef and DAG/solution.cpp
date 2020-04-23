#include <bits/stdc++.h>

#define pb push_back
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 5e2 + 10;

int a[101][N];
bool ch[N][N];
vi g[2 * N];
int n, k;

int capacity[2 * N][2 * N];

int bfs(vi &par) {
    fill(all(par), -1);
    par[0] = -2;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : g[u]) {
            if (par[v] == -1 && capacity[u][v] == 1) {
                par[v] = u;
                if (v == 2 * n + 1)
                    return 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int matching() {
    int ans = 0;
    vi par(2 * n + 2);
    while (int res = bfs(par)) {
        ans += res;
        int cur = 2 * n + 1;
        while (cur != 0) {
            int p = par[cur];
            capacity[p][cur] -= 1;
            capacity[cur][p] += 1;
            cur = p;
        }
    }
    return ans;
}

void solve() {
    cin >> n >> k;
    rf(i, 0, 2 * n + 1) g[i].clear();
    rf(i, 0, 2 * n + 1) rf(j, 0, 2 * n + 1) capacity[i][j] = -1;
    rf(i, 1, n) rf(j, 1, n) ch[i][j] = 1;
    rf(j, 1, k) rf(i, 1, n) cin >> a[j][i];
    rf(l, 1, k) rf(i, 1, n) rf(j, 1, i) ch[a[l][i]][a[l][j]] = 0;

    rf(i, 1, n) {
        capacity[0][i] = 1;
        capacity[i][0] = 0;
        capacity[i + n][n * 2 + 1] = 1;
        capacity[n * 2 + 1][i + n] = 0;
        g[0].pb(i);
        g[i + n].pb(2 * n + 1);
        rf(j, 1, n) if (ch[j][i]) {
            g[j].pb(i + n);
            capacity[j][i + n] = 1;
            g[i + n].pb(j);
            capacity[i + n][j] = 0;
        }
    }

    cout << n - matching() << "\n";
    vi ans(n + 1);
    rf(i, 1, n) rf(j, n + 1, 2 * n) {
        if (capacity[i][j] == 0) {
            ans[i] = j - n;
            break;
        }
    }
    rf(i, 1, n) cout << ans[i] << " ";
    cout << "\n";
    ans.clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}