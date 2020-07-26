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
    int a, b, p;
    cin >> a >> b >> p;
    string s;
    cin >> s;
    int ans = 0;
    int i = sz(s) - 2;
    while (i >= 0) {
        if (s[i] == 'A')
            ans += a;
        if (s[i] == 'B')
            ans += b;
        if (ans > p) {
            cout << i + 2 << "\n";
            return;
        }
        char cur = s[i];
        while (s[i] == cur) {
            i--;
            if (i < 0)
                break;
        }
        
    }
    cout << 1 << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}