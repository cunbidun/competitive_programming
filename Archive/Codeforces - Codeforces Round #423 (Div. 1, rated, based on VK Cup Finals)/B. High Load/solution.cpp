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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    if (k == 2) {
        cout << n - 1 << "\n";
        rf(i, 1, n - 1)  cout << i << " " << i + 1 << '\n'; 
        return 0;
    }
    int t = (n - 1) / k;
    t--;
    cout << 2 + t * 2 + min(2, (n - 1) % k) << "\n";
    rf(i, 2, k + 1) cout << 1 << " " << i << "\n";
    int cnt = k + 2;
    t = (n - 1) % k;
    rf(i, 2, k + 1) {
        int l = i;
        rf(j, 1, (n - 1 - k) / k) {
            cout << l << " " << cnt << "\n";
            l = cnt;
            cnt++;
        }
        if (t) {
            cout << l << " " << cnt << "\n";
            cnt++;
            t--;
        }
    }
}
