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
const ll INFLL = 3e18;

ll ans = INFLL;
set<int> a[3];
int n[3];
ll calc(ll x, ll y, ll z) { return abs(x - y) * abs(x - y) + abs(x - z) * abs(x - z) + abs(z - y) * abs(z - y); }

void cal(int x, int y, int z) {
    for (ll i : a[y]) {
        auto itz = a[z].lower_bound(i);
        if (itz == a[z].end())
            return;

        set<int>::iterator itx = a[x].upper_bound(i);
        if (itx == a[x].begin())
            continue;
itx--;
        ans = min(ans, calc(*itx, i, *itz));
    }
}

int solve() {
    ans = INFLL;
    cin >> n[0] >> n[1] >> n[2];
    rf(i, 0, 2) rf(j, 1, n[i]) {
        ll x;
        cin >> x;
        a[i].insert(x);
    }
    cal(0, 1, 2);
    cal(0, 2, 1);
    cal(1, 0, 2);
    cal(1, 2, 0);
    cal(2, 0, 1);
    cal(2, 1, 0);

    // cout << tmp << "\n";
    cout << ans << "\n";
    a[0].clear();
    a[1].clear();
    a[2].clear();
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