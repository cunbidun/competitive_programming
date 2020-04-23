#include <bits/stdc++.h>

#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

const int N = 2e3 + 1;

int n;
int x, y, x2, y2;
ii a[N];
ll ans = 1e18;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    cin >> x >> y >> x2 >> y2;
    rf(i, 1, n) {
        int u, v;
        cin >> u >> v;
        a[i] = {1LL * (u - x) * (u - x) + 1LL * (v - y) * (v - y), 1LL * (u - x2) * (u - x2) + 1LL * (v - y2) * (v - y2)};
    }
    sort(a + 1, a + 1 + n);
    ll mx = 0;
    rf(i, 1, n) {
        ll tmp = 0;
        mx = max(mx, a[i].second);
        rf(j, i + 1, n) tmp = max(tmp, a[j].second);
        ans = min(ans, tmp + a[i].first);
    }
    cout << min(ans, mx) << "\n";
}