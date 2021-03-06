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

int a, b, q;
ll lcm(int a, int b) { return a / __gcd(a, b) * b; }

ll cal(ll i) {
    ll p1 = 1LL * (i / lcm(a, b)) * max(a, b);
    // cout << p1 << "\n";
    ll r = min(1LL * max(a, b - 1), i % lcm(a, b));
    return i - (p1 + r) - 1;
}

int solve() {
    cin >> a >> b >> q;
    if (a > b)
        swap(a, b);
    while (q--) {
        ll l, r;
        cin >> l >> r;
        
        if (a == b || b == 1 || a == 1) {
            cout << 0 << " ";
            continue;
        }
        cout << cal(r) - cal(l - 1) << " ";
    }
    cout << '\n';
    // cout << cal(1) << "\n";
    // cout << cal(9) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int cnt = 0;
    // for (int i = 1; i <= 10000; i++) {
    //     if (i % 12 % 15 != i % 15 % 12) {
    //         // cout << i << "\n";
    //         cnt++;
    //     }
    // }
    // cout << cnt << "\n";
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}