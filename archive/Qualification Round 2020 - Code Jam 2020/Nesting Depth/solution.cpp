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
    int cnt = 0;
    string s;
    cin >> s;
    rf(i, 1, sz(s)) {
        char x = s[i - 1];
        while (cnt < x - '0') {
            cnt++;
            cout << '(';
        }
        while (cnt > x - '0') {
            cnt--;
            cout << ")";
        }
        cout << x;
    }
    while (cnt > 0) {
        cnt--;
        cout << ")";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    rf(i, 1, t) {
        cout << "Case #" << i << ": ";
        solve();
    }
}