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
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;
    rf(i, 0, n - 1) {
        if (s[i] - 'a' > 'z' - s[i]) {
            if (s[i] - 'a' >= k) {
                s[i] = s[i] - k;        
                k = 0;
                break;
            } else {
                k -= s[i] - 'a';
                s[i] = 'a';
            }
        } else {
            if ('z' - s[i] >= k) {
                s[i] = s[i] + k;
                k = 0;
                break;
            } else {
                k -= 'z' - s[i];
                s[i] = 'z';
            }
        }
    }
    if (k)
        return cout << -1 << '\n', 0;
    cout << s << "\n";
}