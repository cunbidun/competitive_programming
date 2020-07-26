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

struct modInt {
    int MOD;

    modInt(int MOD) { this->MOD = MOD; }

    int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

    int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

    int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

    int pow(int x, ll p) {
        if (p == 0)
            return 1;
        int t = pow(x, p / 2);
        if ((p & 1) == 1)
            return mul(mul(t, t), x);
        return mul(t, t);
    }

    int inv(int x) { return pow(x, MOD - 2); }

    int div(int x, int y) { return mul(x, inv(y)); }
} Op(998244353);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, l, r;
    cin >> n >> m >> l >> r;
    if (n % 2 == 1 && m % 2 == 1)
        return cout << Op.pow(r - l + 1, 1LL * n * m) << "\n", 0;

    int ne = (r / 2 * 2 - (l + 1) / 2 * 2) / 2 + 1;
    int no = r - l + 1 - ne;

    int tmp1 = Op.pow(Op.add(no, ne), 1ll * n * m);
    int tmp2 = Op.pow(Op.sub(no, ne), 1ll * n * m);
    cout << Op.div(Op.add(tmp1, tmp2), 2);
}