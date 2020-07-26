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

ll n, g, b;

bool ch(ll d) {
    ll good = d / (g + b) * g;
    ll rm = d % (g + b);
    good += min(g, rm);
    return good * 2 >= n;
}

void solve() {
    cin >> n >> g >> b;
    ll l = n, r = 1e18;
    while (l != r) {
        if (l + 1 == r) {
            if (!ch(l))
                l = r;
            break;
        }
        ll m = (l + r) >> 1;
        if (ch(m))
            r = m;
        else
            l = m + 1;
    }
    cout << l << "\n";
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