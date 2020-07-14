#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) cout << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi a(n + 1);
        int p = -1;
        rf(i, 1, n) cin >> a[i];
        int last = -1;
        rf(i, 1, n) {
            if (a[i] >= i - 1) {
                last = a[i];
                a[i] = i - 1;
            } else {
                a[i - 1] = last;
                p = i;
                break;
            }
        }
        if (p == -1) {
            cout << "Yes\n";
            continue;
        }
        bool f = 0;
        rf(i, p, n) {
            a[i] = min(a[i - 1] - 1, a[i]);
            if (a[i] < 0) {
                f = true;
                break;
            }
        }

        if (!f)
            cout << "Yes\n";

        else
            cout << "No\n";
    }
}