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

const int N = 3e5 + 1;
const int INF = 2e9;

int n;
ll a[N], b[N], c[N];

int solve() {
    cin >> n;
    rf(i, 1, n) {
        cin >> a[i] >> b[i];
        c[i] = 0;
    }
    ll must = 0;
    ll mn = 1e18;
    rf(i, 2, n) {
        if (a[i] > b[i - 1]) {
            must += a[i] - b[i - 1];
            c[i] = a[i] - b[i - 1];
        }
    }
    if (a[1] > b[n]) {
        must += a[1] - b[n];
        c[1] = a[1] - b[n];
    }
    mn = min(1LL * a[1], mn);
    rf(i, 1, n) { mn = min(mn, a[i] - c[i]); }
    cout << must + mn << "\n";
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