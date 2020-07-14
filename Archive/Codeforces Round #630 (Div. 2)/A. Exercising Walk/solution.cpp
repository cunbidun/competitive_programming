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

void solve() {
    ll a, b, c, d, x, y, x1, x2, y1, y2;
    cin >> a >> b >> c >> d >> x >> y >> x1 >> y1 >> x2 >> y2;
    ll dx = b - a;
    ll dy = d - c;
    if ((a != 0 || b != 0) && x1 == x2) {
        cout << "No\n";
        return;
    }

    if ((c != 0 || d != 0) && y1 == y2) {
        cout << "No\n";
        return;
    }

    if (x + dx > x2 || x + dx < x1) {
        cout << "No\n";
        return;
    }
    if (y + dy > y2 || y + dy < y1) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
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