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
    int n, x;
    cin >> n >> x;
    vi a(1000);
    rf(i, 1, n) {
        int t;
        cin >> t;
        a[t] = 1;
    }
    rf(i, 1, 1000) {
        if (!a[i] && !x) {
            cout << i - 1 << "\n";
            return;
        }
        if (!a[i]) {
            x--;
            continue;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}