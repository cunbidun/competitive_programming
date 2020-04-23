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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 1;
const int INF = 2e9;

int n, m, k, q;
int ask(int x1, int x2, int y) {
    cout << 1 << " " << x1 << " " << x2 << " " << y << endl;
    int tmp;
    cin >> tmp;
    return tmp;
}

void answer(vi &ans) {
    cout << 2 << " ";
    rf(i, 1, q) cout << ans[i] << " ";
    cout << endl;
    int res;
    cin >> res;
}

void solve() {
    cin >> n >> m >> k >> q;
    if (m <= 10) {
        rf(i, 1, q) {
            int x, y;
            cin >> x >> y;
        }
        cout << 2 << " ";
        rf(i, 1, q) cout << m - 1 << " ";
        cout << endl;
        int res;
        cin >> res;
        assert(res == 1);
        return;
    }

    vi ans(11);
    vii q;
    rf(i, 1, 10) {
        int x1, x2;
        cin >> x1 >> x2;
        q.pb({x1, x2});
    }
    int i = 1;
    for (ii p : q)
        ans[i++] = ask(p.first, p.second, 5e8);
    answer(ans);
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
