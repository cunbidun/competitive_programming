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

const int N = 2e5 + 1;
const int INF = 2e9;

int a[N];
int n, k, s[N], p, ch[N];
int solve() {
    cin >> n >> k;
    rf(i, 1, n) {
        cin >> a[i];
        s[i] = 0;
        ch[i] = 0;
    }
    rf(i, 2, n - 1) {
        s[i] = s[i - 1];
        if (a[i] > a[i - 1] && a[i] > a[i + 1]) {
            // cout << i << " ";
            ch[i] = 1;
            s[i]++;
        }
    }
    s[n] = s[n - 1];
    // rf(i, 1, n) cout << s[i] << " ";
    // cout << "\n ";
    p = 0;
    int ans = -1;
    rf(i, k, n) {
        if (ans < s[i] - s[i - k] - ch[i] - ch[i - k + 1]) {
            ans = s[i] - s[i - k] - ch[i] - ch[i - k + 1];
            p = i - k + 1;
        }
        // if (i == 7)
        //     cout << s[7] << "\n";
    }
    cout << ans + 1 << " " << p << '\n';
}
// int pre[200005];

// int solve() {
//     int n, k;
//     cin >> n  >> k;
//     vi a(n);
//     rf(i, 0, n - 1) { cin >> a[i]; }
//     memset(pre, 0, sizeof(pre));
//     rf(i, 1, n - 1) {
//         pre[i] += pre[i - 1];
//         if (i + 1 < n && a[i] > a[i - 1] && a[i] > a[i + 1])
//             pre[i + 1]++;
//     }
//     int ans = 1, ma = 0;
//     for (int i = 0; i + k - 1 < n; i++) {
//         int tmp = pre[i + k - 1] - pre[i];
//         if (i > 0 && i < n - 1 && a[i] > a[i - 1] && a[i] > a[i + 1])
//             tmp--;
//         if (tmp > ma) {
//             ma = tmp;
//             ans = i + 1;
//         }
//     }
//     cout << ma + 1 << " " << ans << "\n";
// }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}