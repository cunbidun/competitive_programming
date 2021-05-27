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
int MOD = 1e9 + 7;
const int INF = 2e9;
int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

int binPow(int x, ll p) {
    if (p == 0)
        return 1;
    int t = binPow(x, p / 2);
    if ((p & 1) == 1)
        return mul(mul(t, t), x);
    return mul(t, t);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int n = sz(s);
    s = '*' + s;
    int a, b;
    cin >> a >> b;
    MOD = b;
    int bp = 0;
    rb(i, n, 1) {
        bp = add(bp, mul((s[i] - '0'), binPow(10, n - i)));
    }
    int ap = 0;
    int p = 0;
    rf(i, 1, n - 1) {
        ap = (ap * 10 + (s[i] - '0')) % a;
        bp = sub(bp, mul((s[i] - '0'), binPow(10, n - i)));
            if (ap == 0 && bp == 0 && s[i + 1] != '0') {
            p = i;
            break;
        }
    }
    if (p!=0) {
        cout << "YES\n";
        rf(i,1,p) cout << s[i];
        cout << "\n";
        rf(i,p + 1, n) cout <<s[i];
        cout << "\n";
    }
    else
        cout << "NO\n";
}