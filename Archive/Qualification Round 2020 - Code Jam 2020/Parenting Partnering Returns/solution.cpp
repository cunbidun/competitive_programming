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

int solve() {
    int n;
    cin >> n;
    vector<pair<ii, int>> a;
    rf(i, 0, n - 1) {
        int x, y;
        cin >> x >> y;
        a.pb({{x, y}, i});
    }
    sort(all(a));
    int f = 0, s = 0;
    vector<char> ans(n);
    rf(i, 0, n - 1) {
        if (a[i].first.first < f && a[i].first.first < s) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
        if (a[i].first.first >= f) {
            ans[a[i].second] = 'C';
            f = a[i].first.second;
            continue;
        }
        if (a[i].first.first >= s) {
            ans[a[i].second] = 'J';
            s = a[i].first.second;
        }
    }
    rf(i, 0, n - 1) { cout << ans[i]; }
    cout << "\n";
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