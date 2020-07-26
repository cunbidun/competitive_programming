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

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    rf(i, 1, n) cin >> a[i];
    int mx = -1, mn = 2e9;
    rf(i, 1, n) {
        if (a[i] == -1) {
            if (i > 1)
                if (a[i - 1] != -1) {
                    mn = min(mn, a[i - 1]);
                    mx = max(mx, a[i - 1]);
                }

            if (i < n)
                if (a[i + 1] != -1) {
                    mn = min(mn, a[i + 1]);
                    mx = max(mx, a[i + 1]);
                }
        }
    }
    if (mx == -1) {
        cout << "0 0 \n";
        return;
    }
    int ans = 0;
    int k = (mx + mn) / 2;
    rf(i, 1, n) if (a[i] == -1) a[i] = k;
    rf(i, 1, n - 1) { ans = max(ans, abs(a[i] - a[i + 1])); }
    cout << ans << " " << k << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}