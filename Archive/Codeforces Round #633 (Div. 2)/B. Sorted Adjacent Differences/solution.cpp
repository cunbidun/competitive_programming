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
    int n;
    cin >> n;
    rf(i, 1, n) cin >> a[i];
    sort(a + 1, a + 1 + n);
    vi ans;
    rf(i, 1, n / 2) {
        ans.pb(i);
        ans.pb(n - i + 1);
    }
    if (n % 2 == 1)
        ans.pb(n / 2 + 1);
    rb(i, sz(ans) - 1, 0) cout << a[ans[i]] << " ";
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