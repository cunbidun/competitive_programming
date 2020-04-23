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
    string s;
    cin >> s;
    s = '*' + s;

    bool has[26];
    rf(i, 0, 25) has[i] = 0;

    string ans = "";
    ans += s[1];
    has[s[1] - 'a'] = 1;
    rf(i, 2, sz(s) - 1) {
        if (!has[s[i] - 'a']) {
            if (ans[0] == s[i - 1])
                ans = s[i] + ans;
            else
                ans += s[i];
            has[s[i] - 'a'] = 1;
        }
    }
    rf(i, 2, sz(s) - 1) {
        bool f = 0;
        rf(j, 0, sz(ans) - 1) {
            if (ans[j] == s[i]) {
                if (j > 0)
                    if (ans[j - 1] == s[i - 1])
                        f = 1;
                if (j < sz(ans) - 1)
                    if (ans[j + 1] == s[i - 1])
                        f = 1;
            }
        }
        if (!f) {
            cout << "NO\n";
            return;
        }
    }
    rf(i, 0, 25) {
        if (!has[i])
            ans += (char)('a' + i);
    }
    cout << "YES\n";
    cout << ans << "\n";
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