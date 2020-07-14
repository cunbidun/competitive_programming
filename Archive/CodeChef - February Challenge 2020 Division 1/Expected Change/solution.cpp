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
} op(1e9 + 7);

void solve() {
    stack<int> cur;
    int cnt0 = 0;
    int n;
    cin >> n;
    int ans = 0;
    int pre = 0;
    rf(i, 1, n) {
        char c;
        cin >> c;
        if (c == '*') {
            cnt0++;
            ans = op.add(ans, pre);
        }
        if (c == '(') {
            ans = op.add(ans, pre);
            cur.push(cnt0 + 1);
            cnt0 = 0;
        } else if (c == ')') {
            ans = op.add(ans, op.add(pre, cnt0 + 1));
            pre = op.add(pre, cnt0 + 1);
            int tmp = cnt0;
            if (!cur.empty()) {
                cnt0 = cur.top();
                cur.pop();
            } else
                cnt0 = 0;

            if (cur.empty())
                cur.push(tmp + 1);
            else
                cur.top() = op.add(cur.top(), tmp + 1);
        }
    }
    if (n % 2 == 0)
        cout << op.div(op.div(ans, n / 2), n + 1) << '\n';
    else
        cout << op.div(op.div(ans, (n + 1) / 2), n) << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}