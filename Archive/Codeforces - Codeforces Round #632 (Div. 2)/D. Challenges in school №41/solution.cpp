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

const int N = 3e3 + 1;
const int INF = 2e9;

int n, k;
vi l;
vi a[N];
vi cur(N);
vi ans;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    rf(i, 1, n) {
        char c;
        cin >> c;
        if (c == 'R')
            l.pb(i);
    }
    int cnt = 0;
    int mx = 0;
    int mi = 0;

    reverse(all(l));

    for (int i : l) {
        rf(j, i, n - 1 - cnt) a[i].pb(j);

        cnt++;
        mx += a[i].size();
    }
    if (k > mx)
        return cout << -1, 0;

    while (mx > k) {
        int last = INF;
        vi mv;
        k--;
        for (int i : l) {
            if (cur[i] != sz(a[i])) {
                if (a[i][cur[i]] < last - 1) {
                    // cout << a[i][cur[i]] << "\n";
                    mx--;
                    mv.pb(a[i][cur[i]]);
                    last = a[i][cur[i]];
                    cur[i]++;

                    if (mx == k)
                        break;
                } else
                    last = a[i][cur[i]];
            }
        }

        if (k == -1)
            return cout << -1, 0;

        ans.pb(sz(mv));
        for (int i : mv) {
            // cout << i << "\n";
            ans.pb(i);
        }
    }

    cnt = 0;
    for (int i : ans) {
        if (cnt == 0)
            cnt = i + 1;
        cout << i << " ";
        cnt--;
        if (cnt == 0)
            cout << "\n";
    }

    for (int i : l) {
        rf(j, cur[i], sz(a[i]) - 1) cout << 1 << " " << a[i][j] << "\n";
    }
}