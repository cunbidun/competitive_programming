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

void solve() {
    ll n;
    int m;
    cin >> n >> m;
    vi cnt(70);
    rf(i, 1, m) {
        int x;
        cin >> x;
        int tmp = 0;
        while (x != 1) {
            x /= 2;
            tmp++;
        }
        cnt[tmp]++;
    }
    int ans = 0;
    rf(i, 0, 61) {
        rf(j, 0, i - 1) {
            cnt[j + 1] += cnt[j] / 2;
            cnt[j] %= 2;
        }
        if (((n >> i) & 1) == 1) {
            int pos = -1;
            rf(j, i, 65) if (cnt[j] != 0) {
                pos = j;
                break;
            }
            if (pos == -1) {
                cout << -1 << "\n";
                return;
            }
            while (pos != i) {
                ans++;
                cnt[pos]--;
                cnt[pos - 1] += 2;
                pos--;
            }
            cnt[pos]--;
        }
    }
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