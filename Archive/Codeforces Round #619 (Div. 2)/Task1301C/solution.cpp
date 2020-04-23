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
    int n, m;
    cin >> n >> m;
    ll ans = 1LL * n * (n + 1) / 2;
    // cout << ans << "\n";
    int p = n - m;
    if (m == 0) {
        cout << "0\n";
        return;
    }
    if (m == n) {
        cout << ans << "\n";
        return;
    }
    m = min(p, m);
    if (m == p)
        m--;
    // cout << m << " " << p << "\n";

    int each = p / (m + 1);
    int re = p % (m + 1);
    // cout << m + 1 << " " << nre << "\n";
    ans -= 1LL * (m + 1 - re) * (each) * (each + 1) / 2;
    ans -= 1LL * re * (each + 1) * (each + 2) / 2;
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}