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
const int MOD = 1e9 + 7;

struct node {
    int aa, ab, ba, bb;
} segment[4 * N];

int n, q, lazy[4 * N];
char a[N];
node I;

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
} Op(MOD);

node combine(node x, node y) {
    node res;
    res.aa = Op.add(Op.mul(x.aa, y.aa), Op.mul(x.ab, y.ba));
    res.ab = Op.add(Op.mul(x.aa, y.ab), Op.mul(x.ab, y.bb));
    res.ba = Op.add(Op.mul(x.ba, y.aa), Op.mul(x.bb, y.ba));
    res.bb = Op.add(Op.mul(x.ba, y.ab), Op.mul(x.bb, y.bb));
    return res;
}

void print(node x) {
    cout << x.aa << " " << x.ab << "\n";
    cout << x.ba << " " << x.bb << "\n";
    cout << "\n";
}

void build(int i, int l, int r) {
    if (l == r) {
        if (a[l] == 'A') {
            segment[i].aa = 1;
            segment[i].ab = 0;
            segment[i].ba = 1;
            segment[i].bb = 1;
        } else {
            segment[i].aa = 1;
            segment[i].ab = 1;
            segment[i].ba = 0;
            segment[i].bb = 1;
        }
        return;
    }
    int m = (l + r) >> 1;
    build(i * 2, l, m);
    build(i * 2 + 1, m + 1, r);
    segment[i] = combine(segment[i * 2], segment[i * 2 + 1]);
}

void lupdate(int i, int l, int r) {
    if (!lazy[i])
        return;
    swap(segment[i].aa, segment[i].bb);
    swap(segment[i].ba, segment[i].ab);
    if (l != r) {
        lazy[i * 2] = 1 - lazy[i * 2];
        lazy[i * 2 + 1] = 1 - lazy[i * 2 + 1];
    }
    lazy[i] = 0;
}

void update(int i, int l, int r, int L, int R) {
    lupdate(i, l, r);
    if (l > r || l > R || L > r)
        return;
    if (L <= l && r <= R) {
        lazy[i] = 1 - lazy[i];
        lupdate(i, l, r);
        return;
    }
    int m = (l + r) >> 1;
    update(i * 2, l, m, L, R);
    update(i * 2 + 1, m + 1, r, L, R);
    segment[i] = combine(segment[i * 2], segment[i * 2 + 1]);
}

node get(int i, int l, int r, int L, int R) {
    lupdate(i, l, r);
    if (l > r || l > R || L > r)
        return I;
    if (L <= l && r <= R)
        return segment[i];
    int m = (l + r) >> 1;
    return combine(get(i * 2, l, m, L, R), get(i * 2 + 1, m + 1, r, L, R));
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    I.aa = 1;
    I.ab = 0;
    I.ba = 0;
    I.bb = 1;
    cin >> n >> q;
    rf(i, 1, n) cin >> a[i];
    build(1, 1, n);
    // print(get(1, 1, n, 2, 5));
    // print(get(1, 1, n, 3, 5));

    // update(1, 1, n, 3, 5);
    // print(get(1, 1, n, 3, 5));

    // print(get(1, 1, n, 1, 1));
    while (q--) {
        int c, l, r;
        cin >> c >> l >> r;
        if (c == 2) {
            int a, b;
            cin >> a >> b;
            node res = get(1, 1, n, l, r);
            // print(res);
            cout << Op.add(Op.mul(a, res.aa), Op.mul(b, res.ba)) << " " << Op.add(Op.mul(a, res.ab), Op.mul(b, res.bb)) << "\n";
        } else {
            update(1, 1, n, l, r);
        }
    }
}