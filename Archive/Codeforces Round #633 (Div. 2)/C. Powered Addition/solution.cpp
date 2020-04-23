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

ll a[N];
int solve() {
    int n;
    cin >> n;
    rf(i, 1, n) cin >> a[i];
    int ans = 0;
    ll mx = -INF;

    rf(i, 1, n) {
        mx = max(mx, a[i]);
        int res = 0;
        ll tmp = mx - a[i];
        while (tmp) {
            res++;
            tmp /= 2;
        }
        ans = max(res, ans);
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}