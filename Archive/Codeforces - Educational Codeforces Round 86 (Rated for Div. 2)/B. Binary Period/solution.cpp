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
    string s;
    cin >> s;
    int ch0 = 0, ch1 = 0;
    rf(i, 0, sz(s) - 1) {
        if (s[i] == '0')
            ch0 = 1;
        if (s[i] == '1')
            ch1 = 1;
    }
    if ((ch0 && !ch1) || (ch1 && !ch0)) {
        cout << s << "\n";
        return 0;
    }
    int cur = 0;
    rf(i, 0, sz(s) - 1) { cout << 0 << 1; }
    cout << "\n";
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