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

const int N = 1e3 + 1;
const int INF = 2e9;

int n;
set<int> a[N];
vi l;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].insert(v);
        a[v].insert(u);
    }
    rf(i, 1, n) {
        if (sz(a[i]) == 1)
            l.pb(i);
    }
    int cur = 0;
    while (1) {
        int u = l[cur++];
        int v = l[cur++];
        cout << "? " << u << " " << v << endl;
        int lca;
        cin >> lca;
        assert(lca != -1);
        if (lca == u)
            return cout << "! " << u << endl, 0;
        if (lca == v)
            return cout << "! " << v << endl, 0;
        assert(sz(a[u]) == 1);
        assert(sz(a[v]) == 1);
        int pu = *a[u].begin();
        int pv = *a[v].begin();
        a[pu].erase(u);
        a[pv].erase(v);
        if (sz(a[pu]) == 0)
            return cout << "! " << pu << endl, 0;
        if (sz(a[pv]) == 0)
            return cout << "! " << pv << endl, 0;
        if (sz(a[pu]) == 1)
            l.pb(pu);
        if (pv != pu)
            if (sz(a[pv]) == 1)
                l.pb(pv);
    }
}