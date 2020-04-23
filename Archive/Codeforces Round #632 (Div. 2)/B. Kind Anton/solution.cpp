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
    int n;
    cin >> n;
    vi a(n + 1), b(n + 1);
    rf(i, 1, n) cin >> a[i];
    rf(i, 1, n) cin >> b[i];
    int x = INF, y = INF;
    rf(i, 1, n) {
        if (a[i] == 1 && x == INF)
            x = i;
        if (a[i] == -1 && y == INF)
            y = i;
    }
    rb(i, n, 1) {
        if (a[i] > b[i]) {
            if (y >= i) {
                cout << "NO\n";
                return;
            }
        }
        if (a[i] < b[i]) {
            if (x >= i) {

                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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