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

int total = 0, cnt[N], limit[N];
vi l[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    rf(i, 1, n) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    rf(i, 1, k) cin >> limit[i];
    int ans = 0;
    rb(i, k, 1) {
        total += cnt[i];
        ans = max(ans, (total + limit[i] - 1) / limit[i]);
    }
    int cur = 1;
    rb(i, k, 1) {
        while (cnt[i]--) {
            l[cur].pb(i);
            cur++;
            if (cur == ans + 1)
                cur = 1;
        }
    }
    cout << ans << '\n';
    rf(i, 1, ans) {
        cout << sz(l[i]) << " ";
        for (int j : l[i]) {
            cout << j << " ";
        }
        cout << "\n";
    }
}