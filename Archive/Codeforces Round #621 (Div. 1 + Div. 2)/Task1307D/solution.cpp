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

int n, m, k;
vi a[N];
vi marked(N);

vi d1;
void dijkstra1(int s) {
    d1.assign(N, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    d1[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du > d1[u])
            continue;
        for (int p : a[u]) {
            int v = p;
            int uv = 1;
            if (d1[v] > du + uv) {
                d1[v] = du + uv;
                pq.push({d1[v], v});
            }
        }
    }
}

vi dn;
void dijkstran(int s) {
    dn.assign(N, INF);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dn[s] = 0;
    pq.push({0, s});
    while (!pq.empty()) {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if (du > dn[u])
            continue;
        for (int p : a[u]) {
            int v = p;
            int uv = 1;
            if (dn[v] > du + uv) {
                dn[v] = du + uv;
                pq.push({dn[v], v});
            }
        }
    }
}

bool cmp(ii a, ii b) {
    if (a.first - a.second != b.first - b.second)
        return a.first - a.second < b.first - b.second;
    if (a.first != b.first)
        return a.first < b.first;
    return b.second < a.second;
}

bool cmp1(ii a, ii b) {
    if (a.first + a.second != b.first + b.second)
        return a.first - a.second < b.first - b.second;
    if (a.first != b.first)
        return a.first < b.first;
    return b.second < a.second;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    rf(i, 1, k) {
        int x;
        cin >> x;
        marked[x] = 1;
    }
    rf(i, 1, m) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    dijkstra1(1);
    dijkstran(n);
    vii l;
    rf(i, 1, n) {
        if (marked[i])
            l.pb({d1[i], dn[i]});
    }
    sort(all(l), cmp);
    int ans = 0;

    rf(i, 1, sz(l) - 1) ans = max(ans, min(l[i].first + l[i - 1].second, l[i].second + l[i - 1].first));
    sort(all(l), cmp1);
    rf(i, 1, sz(l) - 1) ans = max(ans, min(l[i].first + l[i - 1].second, l[i].second + l[i - 1].first));

    cout << min(ans + 1, d1[n]) << "\n";
}