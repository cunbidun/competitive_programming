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

int solve() {
    ll n, l, r;
    cin >> n >> l >> r;

    ll cur = 0;
    int cnt = 1;
    while (1) {
        if (cur + 2 * (n - cnt) >= l)
            break;
        cur += 2 * (n - cnt);
        cnt++;
        if (cnt == n)
            break;
    }
    vi a;

    ll start = cur + 1;
    int nx = cnt + 1;
    while (cur <= r) {
        if (nx == n + 1) {
            cnt++;
            if (cnt >= n) {
                a.pb(1);
                break;
            }
            nx = cnt + 1;
        }
        a.pb(cnt);
        a.pb(nx);
        nx++;
        cur += 2;
    }

    for (int i = l - start; i <= r - start; i++) {
        cout << a[i] << " ";
    }
    
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
