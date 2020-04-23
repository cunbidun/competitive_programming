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
const int MOD = 998244353;
const int SQRT = 300;

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

int inverse(int x) { return binPow(x, MOD - 2); }

struct Query {
    int l, r, id;
} q[N];

bool cmp(Query a, Query b) {
    if (a.l / SQRT != b.l / SQRT)
        return a.l / SQRT < b.l / SQRT;
    return a.r < b.r;
}

int n, nq, x;
vi d;
int a[N], cnt[N], cc[N], fac[N], inv[N], in[N], ans[N];

void update(int p, int v) {
    x ^= cnt[a[p]];
    cc[cnt[a[p]]]--;
    cnt[a[p]] += v;
    x ^= cnt[a[p]];
    cc[cnt[a[p]]]++;
    if (!in[cnt[a[p]]]) {
        in[cnt[a[p]]] = 1;
        d.pb(cnt[a[p]]);
    }
}

int cal(int n, int k) { return mul(fac[n], mul(inv[k], inv[n - k])); }

void solve() {
    cin >> n;
    d = {};
    x = 0;
    map<int, int> mp;
    rf(i, 1, n) {
        cin >> a[i];
        if (mp.find(a[i]) == mp.end())
            mp.insert({a[i], mp.size()});
        a[i] = mp[a[i]];
    }
    cin >> nq;
    rf(i, 1, nq) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + nq + 1, cmp);

    int curL = 1, curR = 0;
    rf(i, 1, nq) {
        while (curL > q[i].l)
            update(--curL, 1);
        while (curR < q[i].r)
            update(++curR, 1);
        while (curL < q[i].l)
            update(curL++, -1);
        while (curR > q[i].r)
            update(curR--, -1);
        int res = 0;
        vi tmp;
        for (int s : d) {
            if (cc[s]) {
                tmp.pb(s);
                int s2 = s ^ x;
                if (s2 < s)
                    res = add(res, mul(cc[s], cal(s, s - s2)));
            } else
                in[s] = 0;
        }
        ans[q[i].id] = res;
        d = tmp;
    }
    rf(i, 1, nq) cout << ans[i] << "\n";
    memset(ans, 0, sizeof(ans));
    memset(cnt, 0, sizeof(cnt));
    memset(cc, 0, sizeof(cc));
    memset(in, 0, sizeof(in));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fac[0] = 1;
    rf(i, 1, N - 1) fac[i] = mul(fac[i - 1], i);
    rf(i, 0, N - 1) inv[i] = inverse(fac[i]);
    int t;
    cin >> t;
    while (t--)
        solve();
}
