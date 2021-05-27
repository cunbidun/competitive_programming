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

const int N = 4e3 + 1;
const int INF = 2e9;

int cnt[N][4];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    string s;
    cin >> n;
    cin >> s;
    s = '*' + s;
    ll ans = 0;

    rf(i, 1, n) {
        rf(j, 1, 3) cnt[i][j] = cnt[i - 1][j];
        if (s[i] == 'R')
            cnt[i][1]++;
        if (s[i] == 'G')
            cnt[i][2]++;
        if (s[i] == 'B')
            cnt[i][3]++;
    }

    rf(i, 1, n) {
        rf(j, i + 1, n) if (s[i] != s[j]) {
            if (s[i] != 'R' && s[j] != 'R') {

                ans += cnt[n][1] - cnt[j][1];
                if (j + j - i  <= n && s[j + j - i ] == 'R')
                    ans--;
            }

            if (s[i] != 'G' && s[j] != 'G') {
                ans += cnt[n][2] - cnt[j][2];
                if (j + j - i  <= n && s[j + j - i ] == 'G')
                    ans--;
            }
            if (s[i] != 'B' && s[j] != 'B') {
                ans += cnt[n][3] - cnt[j][3];
                if (j + j - i  <= n && s[j + j - i ] == 'B')
                    ans--;
            }
        }
    }
    cout << ans << '\n';
}
