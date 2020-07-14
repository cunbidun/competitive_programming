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

const int N = 1e2 + 1;
const int INF = 2e9;

int a[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    rf(i, 1, q) {
        int cnt = 0;
        int ans = 0;
        int t, k, d;
        cin >> t >> k >> d;
        rf(j, 1, n) {
            if (a[j] < t) {
                cnt++;
                ans += j;
                if (cnt == k) 
                    break;
            }
        }
        if (cnt != k) {
            cout << -1 << "\n";
            continue;
        }
        cnt = 0;
        rf(j, 1, n) {
            if (a[j] < t) {
                a[j] = t + d - 1;
                cnt++;
                if (cnt == k)
                    break;
            }
        }
        cout << ans << "\n";
    }
}