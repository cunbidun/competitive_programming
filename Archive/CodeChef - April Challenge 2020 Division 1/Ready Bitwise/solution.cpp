#include <bits/stdc++.h>

#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define rf(i, a, b) for (int(i) = (a); (i) <= (b); (i)++)
#define rb(i, b, a) for (int(i) = (b); (i) >= (a); (i)--)
#define int long long
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

struct val {
    int v[4];
};

char a[] = {'0', '1', 'a', 'A'};

char eval(char l, char m, char r) {
    if (m == '|') {
        if (l == '0' && r == '0')
            return '0';
        if (l == '1' || r == '1')
            return '1';
        if (l == 'a' && r != 'A')
            return 'a';
        if (l == '0' && r == 'a')
            return 'a';
        if (l == 'A' && r == 'a')
            return '1';
        if (l == 'a' && r == 'A')
            return '1';
        return 'A';
    }
    if (m == '^') {
        if (l == r)
            return '0';
        if (l == '0')
            return r;
        if (r == '0')
            return l;
        if (l == 'A' && r == 'a')
            return '1';
        if (l == 'a' && r == 'A')
            return '1';
        if (l == '1' && r == 'a')
            return 'A';
        if (l == 'a' && r == '1')
            return 'A';
        return 'a';
    }
    if (m == '&') {
        if (l == '0' || r == '0')
            return '0';
        if (l == '1')
            return r;
        if (r == '1')
            return l;
        if (l == r)
            return r;
        return '0';
    }
}
val cal(string s) {
    val res;
    if (s == "#") {
        res.v[0] = Op.div(1, 4);
        res.v[1] = Op.div(1, 4);
        res.v[2] = Op.div(1, 4);
        res.v[3] = Op.div(1, 4);
        return res;
    } else {
        res.v[0] = 0;
        res.v[1] = 0;
        res.v[2] = 0;
        res.v[3] = 0;
    }

    int cnt = 0;

    char p;
    val l, r;
    rf(i, 0, sz(s) - 1) {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        else if (cnt == 1 && (s[i] == '|' || s[i] == '^' || s[i] == '&')) {
            p = s[i];
            l = cal(s.substr(1, i - 1));
            r = cal(s.substr(i + 1, sz(s) - i - 2));
            break;
        }
    }
    rf(i, 0, 3) rf(j, 0, 3) {
        if (eval(a[i], p, a[j]) == '0')
            res.v[0] = Op.add(res.v[0], Op.mul(l.v[i], r.v[j]));
        if (eval(a[i], p, a[j]) == '1')
            res.v[1] = Op.add(res.v[1], Op.mul(l.v[i], r.v[j]));
        if (eval(a[i], p, a[j]) == 'a')
            res.v[2] = Op.add(res.v[2], Op.mul(l.v[i], r.v[j]));
        if (eval(a[i], p, a[j]) == 'A')
            res.v[3] = Op.add(res.v[3], Op.mul(l.v[i], r.v[j]));
    }
    return res;
}

int solve() {
    string s;
    cin >> s;
    val ans = cal(s);
    cout << ans.v[0] << " " << ans.v[1] << " " << ans.v[2] << " " << ans.v[3] << "\n";
}

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}