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
ll cnt[26];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    ll ans = 0;
    ll mx = 0;
    rf(k, 0, sz(s) - 1) {
        cnt[s[k] - 'a']++;
        mx = max(mx, cnt[s[k] - 'a']);
    }
    rf(i, 0, 25) rf(j, 0, 25) {
        ll cnt = 0;
        ll res = 0;
        rf(k, 0, sz(s) - 1) {
            if (s[k] == (char)('a' + j))
                res += cnt;
            if (s[k] == (char)('a' + i))
                cnt++;
        }
        ans = max(ans, res);
    }
    cout << max(ans, mx) << "\n";
}