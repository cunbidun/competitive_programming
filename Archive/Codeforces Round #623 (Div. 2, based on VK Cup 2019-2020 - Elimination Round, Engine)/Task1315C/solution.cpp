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
    bool mark[2 * n + 1];
    rf(i, 1, 2 * n) mark[i] = 0;
    vi l;
    vi ans(2 * n + 1);
    rf(i, 1, n) {
        cin >> ans[i * 2 - 1];
        mark[ans[i * 2 - 1]] = 1;
    }
    rf(i, 1, 2 * n) if (!mark[i]) l.pb(i);
    rf(i, 1, n) {
        int mn = INF;
        for (int j : l)
            if (!mark[j] && j > ans[i * 2 - 1]) {
                mn = min(j, mn);
            }
        if (mn == INF) {
            cout << -1 << "\n";
            return;
        }
        ans[i * 2] = mn;
        mark[mn] = 1;
    }
    for (int i = 1; i < sz(ans); i++)
        cout << ans[i] << " ";
    cout << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}