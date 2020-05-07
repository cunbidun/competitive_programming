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

int a[N], b[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;
    rf(i, 1, n) cin >> a[i];
    rf(j, 1, m) cin >> b[j];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int pos = 1;
    rf(i, 1, n) {
        while (b[pos] < a[i] - k) {
            pos++;
        }
        if (pos > m)
            break;
        if (b[pos] > a[i] + k)
            continue;
        ans++;
        pos++;
    }
    cout << ans << "\n";
}