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

int f[50][50];
void solve() {
    int d, m;
    cin >> d >> m;
    memset(f, 0, sizeof(f));
    int h = 0;
    int tmp = 1;
    while (tmp <= d) {
        tmp *= 2;
        h++;
    }
    if (h != 0)
        h--;
    // cout << h << "\n";
    f[1][h] = d - (1 << h) + 1;
    rf(i, 0, h - 1) f[1][i] = (1 << i);

    rf(i, 2, h + 1) {
        rf(j, 0, h) {
            rf(k, j+1, h) {
                // if (k + i <= h + 1) {
                    f[i][j] = (f[i][j] + (1LL * (1 << j) * f[i - 1][k]) % m) % m;
                // }
            }
        }
    }
    // cout << f[3][0] << "\n";

    int ans = 0;
    rf(i, 1, h + 1) { rf(j, 0, h) ans = (ans + f[i][j]) % m; }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}