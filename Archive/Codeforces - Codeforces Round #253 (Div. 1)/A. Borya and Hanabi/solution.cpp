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

int n;
set<char> a1, a2;
map<int, char> mp;

set<string> s;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    mp[0] = '1';
    mp[1] = '2';
    mp[2] = '3';
    mp[3] = '4';
    mp[4] = '5';
    mp[5] = 'W';
    mp[6] = 'Y';
    mp[7] = 'R';
    mp[8] = 'G';
    mp[9] = 'B';

    cin >> n;

    rf(i, 1, n) {
        string x;
        cin >> x;
        s.insert(x);
    }

    if (sz(s) == 1)
        return cout << 0 << "\n", 0;

    vector<string> a;
    for (string c : s)
        a.pb(c);

    int ans = 11;
    rf(i, 0, (1 << 10) - 1) {
        set<int> cur;

        vi tmp(sz(a));
        rf(j, 0, 9) if ((i >> j) & 1) {
            rf(k, 0, sz(a) - 1) {
                if (a[k][0] == mp[j] || a[k][1] == mp[j]) {
                    tmp[k] = tmp[k] * 2 + 1;
                } else
                    tmp[k] *= 2;
            }
        }
        for (int num : tmp) {
            // cout << num << " ";
            cur.insert(num);
        }
        if (sz(cur) == sz(s))
            ans = min(ans, __builtin_popcount(i));
    }
    cout << ans << "\n";
}