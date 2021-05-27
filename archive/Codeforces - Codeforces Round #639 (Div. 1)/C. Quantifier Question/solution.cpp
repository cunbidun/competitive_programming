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

template <class T1, class T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &a) {
    return os << '(' << a.first << ", " << a.second << ')';
}
template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}

const int N = 2e5 + 1;
const int INF = 2e9;

int n, m, f;
vi a[N], p[N], l;
int vis[N], mn1[N], mn2[N];

void dfs(int u) {
    vis[u] = 1;
    for (int v : a[u]) {
        if (vis[v] == 1) {
            f = 1;
            return;
        }
        if (!vis[v])
            dfs(v);
    }
    l.pb(u);
    vis[u] = 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, n) {
        mn1[i] = i;
        mn2[i] = i;
    }
    rf(i, 1, m) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        p[v].pb(u);
    }
    rf(i, 1, n) if (!vis[i]) dfs(i);

    if (f)
        return cout << -1 << "\n", 0;

    for (int u : l) {
        for (int v : p[u]) {
            mn1[v] = min(mn1[v], mn1[u]);
        }
    }

    reverse(all(l));

    // cout << l << "\n";

    for (int u : l) {
        for (int v : a[u]) {
            mn2[v] = min(mn2[v], mn2[u]);
        }
    }

    int ans = 0;
    rf(i, 1, n) if (min(mn1[i], mn2[i]) == i) ans++;
    cout << ans << "\n";
    rf(i, 1, n) {
        if (min(mn1[i], mn2[i]) == i)
            cout << "A";
        else
            cout << "E";
    }
    cout << "\n";
}