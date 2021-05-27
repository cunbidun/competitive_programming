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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (y >= x) {
            if (y % 2 == 1) {
                cout << 1LL * y * y - x + 1 << "\n";
            } else
                cout << 1LL * y * y - y - y + 2 + x - 1 << "\n";
        } else {
            if (x % 2 == 0) {
                cout << 1LL * x * x - y + 1 << "\n";
            } else
                cout << 1LL * (x - 1) * (x - 1) + 1 + y - 1 << "\n";
        }
    }
}