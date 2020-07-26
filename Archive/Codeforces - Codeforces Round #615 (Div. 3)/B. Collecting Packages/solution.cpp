#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) out << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e3 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

ii a[N];
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        rf(i, 1, n) {
            int x, y;
            cin >> x >> y;
            a[i] = {x, y};
        }
        sort(a + 1, a + n + 1);
        string ans = "";
        int pos = 1;
        bool f = 0;
        rf(i, 1, n) {
            if (a[i].F < a[i - 1].F || a[i].S < a[i - 1].S) {
                f = 1;
                break;
            }
            rf(j, a[i - 1].F, a[i].F - 1) ans += "R";
            rf(j, a[i - 1].S, a[i].S - 1) ans += "U";
        }
        if (!f) {
            cout << "YES\n";
            cout << ans << "\n";
        } else
            cout << "NO\n";
    }
}