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
    int n;
    cin >> n;
    // cout << n << "\n";
    int x = 0, y = 0;
    bool f = 0;
    while (n--) {
        int a, b;
        cin >> a >> b;
        if (a < x || b < y || a - x < b - y || a < b)
            f = 1;
        x = a;
        y = b;
    }
    if (f)
        cout << "NO\n";
    else
        cout << "YES\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}