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
    int n, q;
    cin >> n >> q;
    vi a(n + 1), b(n + 1), sa(n + 1), sb(n + 1);

    rf(i, 1, n) cin >> a[i], a[i] %= 2, sa[i] = sa[i - 1] + a[i];
    rf(i, 1, n) cin >> b[i], b[i] %= 2, sb[i] = sb[i - 1] + b[i];

    while (q--) {
        int x1, x2, y1, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int tx = min(x1, x2);
        int ty = min(y1, y2);
        int bx = max(x1, x2);
        int by = max(y1, y2);
        if ((sa[bx] - sa[tx - 1] == 0 && sb[by] - sb[ty - 1] == 0) || (sa[bx] - sa[tx - 1] == bx - tx + 1 && sb[by] - sb[ty - 1] == by - ty + 1))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}