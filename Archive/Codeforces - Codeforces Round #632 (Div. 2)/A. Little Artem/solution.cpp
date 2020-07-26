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
    int n, m;
    cin >> n >> m;
    rf(i, 1, n) {
        rf(j, 1, m) {
            if ((i + j) % 2 == 0)
                cout << "B";
            else {
                if (n * m % 2==0 && i == 1 && j == 2)
                    cout << "B";
                else
                    cout << "W";
            }
        }
        cout << "\n";
    }
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