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

const int N = 1e6 + 1;
const int INF = 2e9;

int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    rf(i, 1, n) cin >> a[i];
    int ans = 0;
    int i = n;
    int d = n;
    while (i > 0) {
        if (d >= i)
            ans++;
        d = min(d, i - a[i] - 1);
        // cout << i - a[i] - 1 << "\n";
        i--;
    }
    cout << ans << "\n";
}