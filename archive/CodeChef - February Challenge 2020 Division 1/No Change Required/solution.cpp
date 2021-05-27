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
    int n, p;
    cin >> n >> p;
    vi a(n + 1);
    rf(i, 1, n) cin >> a[i];
    rf(i, 1, n) if (p % a[i] != 0) {
        cout << "YES ";
        rf(j, 1, i - 1) cout << 0 << " ";
        cout << (p + a[i] - 1) / a[i] << " ";
        rf(j, i + 1, n) cout << 0 << " ";
        cout << "\n";
        return;
    }
    rf(i, 2, n) if (a[i] % a[i - 1] != 0) {
        cout << "YES ";
        rf(j, 1, i - 2) cout << 0 << " ";
        cout << (p - a[i] + a[i - 1] - 1) / a[i - 1] << " " << 1 << " ";
        rf(j, i + 1, n) cout << 0 << " ";
        cout << "\n";
        return;
    }
    cout << "NO\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}