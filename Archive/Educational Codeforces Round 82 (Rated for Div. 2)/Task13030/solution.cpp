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
void solve() {
    string s;
    cin >> s;
    int l = -1;
    int f = 10000;
    int cnt = 0;
    rf(i, 0, sz(s) - 1) {
        if (s[i] == '1') {
            f = min(f, i);
            l = max(l, i);
            cnt++;
        }
    }
    if(cnt == 0) cout << 0 <<"\n";
    else
    cout << (l - f + 1 - cnt) << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}