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

int n, a[N], ans[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int p = 0;
    rf(i, 1, n) {
        cin >> a[i];
        if (!p && a[i] == 0)
            p = i;
    }
    rb(i, p, 1) ans[i] = p - i;
    rf(i, p, n) {
        ans[i] = i - p;
        if (a[i] == 0) {
            p = i;
            rb(i, p, 1) {
                if (ans[i] < p - i)
                    break;
                ans[i] = p - i;
            }
        }
    }
    rf(i, 1, n) cout << ans[i] << " ";
    cout << "\n";
}