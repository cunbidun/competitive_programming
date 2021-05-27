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

int a[N];
int solve() {
    int n, x;
    cin >> n >> x;
    rf(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int ans = 0;
    ll sum = 0;
    rb(i, n, 1) {
        sum += a[i];
        if (sum >= 1LL * x * (n - i + 1))
            ans = n - i + 1;
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