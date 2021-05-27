#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) out << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int n, lvl[2020];
vi a[2020];
int dfs(int u) {
    lvl[u] = 1;
    for (int v : a[u])
        lvl[u] = max(lvl[u], dfs(v) + 1);
    return lvl[u];
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp != -1)
            a[tmp].pb(i);
    }
    rf(i, 1, n) {
        if (!lvl[i]) {
            dfs(i);
        }
    }
    int ans = 0;
    rf(i, 1, n) { ans = max(ans, lvl[i]); }
    cout << ans << "\n";
}