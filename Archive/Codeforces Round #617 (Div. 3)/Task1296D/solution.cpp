#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) cout << (#x) << " = " << (x) << endl
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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    int ans = 0;
    vi cost(n + 1);
    rf(i, 1, n) {
        int x;
        cin >> x;
        x %= (a + b);
        if (x == 0)
            x += a + b;
        cost[i] = (x + a - 1) / a;
    }
    sort(all(cost));
    // rf(i, 1, n) cout << cost[i] << " ";
    cout << "\n";
    rf(i, 1, n) {
        if (k >= cost[i] - 1) {
            ans++;
            k -= cost[i] - 1;
        } else
            break;
    }
    cout << ans << "\n";
}