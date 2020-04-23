#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) out << (#x) << " = " << (x) << endl
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
typedef vector<ii> vii;

const int N = 2e5 + 1;
const int MOD = 1e9 + 7;
const int INF = 2e9;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        int a, b, c;
        a = b = c = -1;
        cin >> n;
        rf(i, 2, sqrt(n)) {
            if (n % i == 0) {
                a = i;
                break;
            }
        }
        if (a == -1) {
            cout << "NO\n";
            continue;
        }
        n /= a;
        rf(i, a + 1, sqrt(n)) {
            if (n % i == 0 && n / i != i) {
                b = i;
                break;
            }
        }
        if (b == -1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        cout << a << " " << b << " " << n / b << "\n";
    }
}