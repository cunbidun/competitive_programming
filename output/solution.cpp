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

const int N = 2e5 + 1;
const int INF = 2e9;
const ll INFLL = 7e18;  
ll ans = INFLL;

ll n, m, k, x, s;
ll c[N], d[N];
pair<ll, ll> a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k >> x >> s;
    rf(i, 1, m) cin >> a[i].second;
    rf(i, 1, m) cin >> a[i].first;
    rf(i, 1, k) cin >> c[i];
    rf(i, 1, k) cin >> d[i];
    int p = k;
    sort(a + 1, a + m + 1);
    a[0] = {0, x};
    c[0] = 0;
    d[0] = 0;
    rf(i, 0, m) {
        while (p > 0 && d[p] + a[i].first > s)
            p--;
        if (d[p] + a[i].first <= s)
            ans = min(ans, (n - c[p]) * a[i].second);
    }
    cout << ans << "\n";
}