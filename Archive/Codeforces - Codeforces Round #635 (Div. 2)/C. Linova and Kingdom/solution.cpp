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
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int INF = 2e9;

int n, k;
vi a[N];
int lvl[N];
int s[N];
bool ch[N];
ll ans = 0;
priority_queue<ii> pq;

void dfs(int u, int l) {
    s[u] = 1;
    for (int v : a[u])
        if (v != l) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
            s[u] += s[v];
        }
}

void cal(int u, int l) {
    if (ch[u]) {
        // cout << u << " " << s[u] << " " << lvl[u] << "\n";
        ans += 1LL * s[u] * lvl[u];
        return;
    }
    for (int v : a[u])
        if (v != l) {
            cal(v, u);
        }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    rf(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dfs(1, 1);
    rf(i, 1, n) pq.push({lvl[i] - s[i] + 1, i});
    while (k--) {
        ii u = pq.top();
        pq.pop();
        ch[u.second] = 1;
    }
    cal(1, 1);
    cout << ans << "\n";
}