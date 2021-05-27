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

const int N = 1e5 + 1;
const int INF = 2e9;

int x[N];
int y[N];

int n, m;
int p[N];
bool vis[N], d;
vi a[N];

void dfs(int u) {
    
    vis[u] = 1;
    int cnt = 0;
    int next = 0;
    for (int v : a[u]) {
        p[v]--;
        if (p[v] == 0) {
            cnt++;
            next = v;
        }
    }
    if(sz(a[u]) == 0) return;
    if (cnt != 1) {
        d = 0;
        return;
    }
    dfs(next);
}

bool ch(int mid) {
    d = 1;
    rf(i, 1, n) {
        p[i] = 0;
        vis[i] = 0;
        a[i].clear();
    }
    rf(i, 1, mid) {
        p[y[i]]++;
        a[x[i]].pb(y[i]);
    }
    int cnt = 0;
    int r = 0;
    rf(i, 1, n) if (p[i] == 0) {
        r = i;
        cnt++;
    }
    if (cnt > 1)
        return 0;
    dfs(r);
    // cout << r << "\n";
    return d;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    rf(i, 1, m) cin >> x[i] >> y[i];

    if (!ch(m))
        return cout << -1 << "\n", 0;

    int l = 1, r = m;
    while (l != r) {
        if (l + 1 == r) {
            if (!ch(l))
                l = r;
            break;
        }
        int mid = (l + r) >> 1;
        if (ch(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << "\n";
}