#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) cout << (#x) << " = " << (x) << endl
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

vi a[N];
vi lvl(N);
vector<double> prob(N);

void dfs(int u, int l) {
    for (int v : a[u])
        if (v != l) {
            lvl[v] = lvl[u] + 1;
            if (u == 1)
                prob[v] = (double)prob[u] / sz(a[u]);
            else
                prob[v] = (double)prob[u] / (sz(a[u]) - 1);
            dfs(v, u);
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    rf(i, 1, n - 1) {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    lvl[1] = 0;
    prob[1] = 1.0;
    dfs(1, 1);
    double ans = 0.0;
    rf(i, 2, n) if (sz(a[i]) == 1) ans += prob[i] * (double)lvl[i];
    cout << ans << "\n";
}