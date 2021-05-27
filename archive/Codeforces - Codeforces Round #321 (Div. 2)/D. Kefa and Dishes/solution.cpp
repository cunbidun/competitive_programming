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

int n, m, k;
int c[20][20];
int a[20];
ll f[19][1 << 18 + 1];

ll ans = 0;
ll cal(int i, int mask) {
    if (f[i][mask] != -1)
        return f[i][mask];
    f[i][mask] = 0;

    rf(j, 1, n) if (i != j &&((mask >> (j - 1)) & 1) == 1) {
        f[i][mask] = max(f[i][mask], cal(j, mask ^ (1 << (i - 1))) + c[j][i]);
        // cal
    }
    f[i][mask] += a[i];
    return f[i][mask];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    memset(f, -1, sizeof(f));
    rf(i, 1, n) cin >> a[i];
    rf(i, 1, k) {
        int x, y, t;
        cin >> x >> y >> t;
        c[x][y] = t;
    }

    rf(i, 1, n) { cal(i, (1 << n) -1); }
    rf(i, 1, n) rf(j, 0, (1 << n) - 1) if (__builtin_popcount(j) == m) ans = max(ans, f[i][j]);

    cout << ans << "\n";
}