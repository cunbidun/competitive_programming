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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1);
    vi s(n + 1);
    rf(i, 1, n) cin >> a[i], s[i] = s[i - 1] + a[i];
    vector<char> m(n + 1);
    rf(i, 1, n) cin >> m[i];
    int cur = 0;
    rb(i, n, 1) if (m[i] == '1') {
        cur = i;
        break;
    }
    if (cur == 0)
        return cout << 0 << "\n", 0;
    int ans = 0;
    int sum = 0;
    while (cur > 0) {
        ans = max(ans, s[cur - 1] + sum);
        sum += a[cur];
        while (cur > 0 && m[--cur] == '0')
            ;
    }
    ans = max(ans,sum);
    cout << ans << "\n";
}