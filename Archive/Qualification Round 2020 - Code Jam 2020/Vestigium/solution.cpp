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
    int n;
    cin >> n;
    set<int> r[n + 1], c[n + 1];
    int k = 0, R = 0, C = 0;

    rf(i, 1, n) rf(j, 1, n) {
        int x;
        cin >> x;
        if (i == j)
            k += x;
        r[i].insert(x);
        c[j].insert(x);
    }
    rf(i, 1, n) {
        if (sz(r[i]) != n)
            R++;
        if (sz(c[i]) != n)
            C++;
    }
    cout << k << " " << R << " " << C << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rf(i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }
}