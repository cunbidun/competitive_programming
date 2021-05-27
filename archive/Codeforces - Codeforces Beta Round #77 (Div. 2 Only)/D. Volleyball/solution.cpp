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
typedef pair<ll, int> li;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << '(' << a.first << ", " << a.second << ')'; }
template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

const int N = 1e3 + 1;
const int INF = 1e9;
const ll INFLL = 1e17;

int n, m, s, e, t[N], c[N], dis[N][N];
vi a[N];
vii g[N];
bool vis[N];

vector<ll> d;
void dijkstra(int s) {
    d.assign(N, INFLL);
    priority_queue<li, vector<li>, greater<li>> pq;
    d[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        ll du = pq.top().first;
        pq.pop();
        if (du > d[u])
            continue;
        for (ii p : g[u]) {
            int v = p.second;
            ll uv = p.first;
            if (d[v] > du + uv) {
                d[v] = du + uv;
                pq.push({d[v], v});
            }
        }
    }
}

void bfs(int r) {
    queue<ii> q;
    q.push({r, t[r]});
    while (!q.empty()) {
        int u = q.front().first;
        int l = q.front().second;
        q.pop();
        if (vis[u])
            continue;
        vis[u] = 1;
        g[r].pb({c[r], u});
        for (int v : a[u])
            if (!vis[v] && l - dis[u][v] >= 0)
                q.push({v, l - dis[u][v]});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    cin >> s >> e;
    rf(i, 1, n) rf(j, 1, n) dis[i][j] = INF;
    rf(i, 1, m) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb(v);
        a[v].pb(u);
        dis[u][v] = min(dis[u][v], w);
        dis[v][u] = dis[u][v];
    }

    rf(i, 1, n) cin >> t[i] >> c[i];
    rf(i, 1, n) {
        memset(vis, 0, sizeof(vis));
        bfs(i);
        // cout << g[i] << "\n";
    }

    dijkstra(s);
    if (d[e] == INFLL)
        return cout << -1 << "\n", 0;
    cout << d[e] << "\n";
}