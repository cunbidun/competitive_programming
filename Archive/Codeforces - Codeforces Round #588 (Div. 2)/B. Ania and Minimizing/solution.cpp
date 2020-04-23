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
    string s;
    int n, k;
    cin >> n >> k;
    if (n == 1 && k != 0) {
        cout << 0 << "\n";
        return 0;
    }
    cin >> s;
    rf(i, 0, sz(s) - 1) {
        if (!k)
            break;
        if (i == 0 && s[i] != '1') {
            s[i] = '1';
            k--;
        } else if (i != 0 && s[i] != '0') {
            s[i] = '0';
            k--;
        }
    }
    cout << s;
}