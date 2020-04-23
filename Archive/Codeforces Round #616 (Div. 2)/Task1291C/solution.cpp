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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vi a(n + 1);
        k = min(k, m - 1);
        rf(i, 1, n) cin >> a[i];
        int ans = 0;
        rf(l, 0, k) {
            int r = n - (k - l) + 1;
            int res = INF;
            rf(i, 0, m - k - 1) {
                int tmp = max(a[l + i + 1], a[r - (m - k - 1 - i) - 1]);
                res = min(res, tmp);
                // cout << l + 1 << " " << r - 1 << " " << i << " " << tmp << "\n";
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
}