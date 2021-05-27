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
template <class T1, class T2> ostream &operator<<(ostream &os, const pair<T1, T2> &a) { return os << '(' << a.first << ", " << a.second << ')'; }

template <class T> ostream &operator<<(ostream &os, const vector<T> &a) {
    os << '[';
    for (unsigned int i = 0; i < a.size(); i++)
        os << a[i] << (i < a.size() - 1 ? ", " : "");
    os << ']';
    return os;
}
const int N = 1e5 + 1;
const int INF = 2e9;

void solve() {
    int n;
    cin >> n;
    vi a(n + 1);
    int mx = 0;
    rf(i, 1, n) {
        cin >> a[i];
        mx = max(a[i], mx);
    }
    if (n - mx > mx) {
        cout << 0 << "\n";
        return;
    }
    vi r, l, m;
    rf(i, 1, n - mx) l.pb(a[i]);
    rb(i, n, mx + 1) r.pb(a[i]);
    rf(i, n - mx + 1, mx) m.pb(a[i]);
    sort(all(l));
    sort(all(r));
    sort(all(m));
    reverse(all(m));
    int fl = 0, fr = 0, fm = 0;
    rf(i, 0, sz(m) - 1) {
        if (m[i] != mx - i) {
            fm = 1;
        }
    }

    rf(i, 0, sz(l) - 1) {
        if (l[i] != i + 1)
            fl = 1;
    }

    rf(i, 0, sz(r) - 1) if (r[i] != i + 1) fr = 1;
    if ((fl && fr)) {
        cout << 0 << "\n";
        return;
    }

    if (fl) {
        l.clear();
        rf(i, 1, mx) l.pb(a[i]);
        sort(all(l));
        // cout << l << "\n";
        rf(i, 0, sz(l) - 1) {
            if (l[i] != i + 1) {
                cout << 0 << "\n";
                return;
            }
        }
        cout << 1 << "\n";
        cout << mx << " " << n - mx << "\n";
        return;
    }

    if (fr) {
        r.clear();
        rb(i, n, n - mx + 1) r.pb(a[i]);
        sort(all(r));
        // cout << r << "\n";
        rf(i, 0, sz(r) - 1) {
            if (r[i] != i + 1) {
                cout << 0 << "\n";
                return;
            }
        }
        cout << 1 << "\n";
        cout << n - mx << " " << mx << "\n";
        return;
    }

    if (fm) {
        cout << 0 << "\n";
        return;
    }
    if(mx == n - mx) {
         cout << 1 << "\n";
        cout << n - mx << " " << mx << "\n";
        return;
    }
    cout << 2 << "\n";
    cout << n - mx << " " << mx << "\n";
    cout << mx << " " << n - mx << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}