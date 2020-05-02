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

int n, k;
ll a[N], sum[N];

bool check(int m) {
    int p = 0;
    rf(i, 1, n) {
        ll mn = a[i];
        ll mx = min(mn + m, a[n]);
        ll left = i * mn - sum[i];

        if (mn * n > sum[n])
            break;

        while (p <= n && a[p] < a[i] + m)
            p++;

        ll right = 0;
        if (p != n + 1) {
            right = sum[n] - sum[p - 1] - (n - p + 1) * mx;
        }

        if (mx * n < sum[n])
            continue;
        if (max(left, right) <= k) {
            cout << mn << " " << mx << "\n";
            return 1;
        }
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    rf(i, 1, n) {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    sort(a + 1, a + 1 + n);
    int l = 0, r = 1e9;
    while (l != r) {
        if (l + 1 == r) {
            if (!check(l))
                l = r;
            break;
        }
        int m = (l + r) >> 1;
        if (check(m))
            r = m;
        else
            l = m;
    }
    cout << l << '\n';
}