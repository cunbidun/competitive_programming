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
ll a[N];
ll sum[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    rf(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    rf(i, 1, n) sum[i] = sum[i - 1] + a[i];
    int ans = 1;
    int num = a[1];

    rf(i, 1, n) {
        int l = 1, r = i;
        while (l != r) {
            if (l + 1 == r) {
                if (a[i] * r - (sum[i] - sum[i - r]) <= k)
                    l = r;
                break;
            }
            int m = (l + r) >> 1;
            if (a[i] * m - (sum[i] - sum[i - m]) > k)
                r = m - 1;
            else
                l = m;
        }
        if (l > ans) {
            ans = l;
            num = a[i];
        }
    }
    cout << ans << " " << num << "\n";
}