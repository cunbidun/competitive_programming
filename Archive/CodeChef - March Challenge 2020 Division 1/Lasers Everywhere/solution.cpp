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

const int N = 2e5 + 1;
const int INF = 2e9;
int n, q;

struct Query {
    int x1, x2, y;
    Query(int _x1, int _x2, int _y) {
        x1 = _x1;
        x2 = _x2;
        y = _y;
    }
};

vi a(N);
vector<Query> query;
map<ii, int> val;
vi order[N];

vi bit(N);

vi l;
map<int, int> mp;
void compress() {
    sort(all(l));
    l.resize(distance(l.begin(), unique(all(l))));
    for (int i : l)
        mp[i] = sz(mp) + 1;
}

void update(int p, int v) {
    for (; p < N; p += p & (-p))
        bit[p] += v;
}

void update(int l, int r, int v) {
    update(l, v);
    update(r + 1, -v);
}

int get_sum(int p) {
    int sum = 0;
    for (; p; p -= p & (-p))
        sum += bit[p];
    return sum;
}

void solve() {
    bit.assign(N - 1, 0);
    cin >> n >> q;
    rf(i, 1, n) cin >> a[i], l.pb(a[i]);
    rf(i, 1, q) {
        int x1, x2, y;
        cin >> x1 >> x2 >> y;
        query.pb({x1, x2, y});
        l.pb(y);
    }
    compress();
    rf(i, 1, n) a[i] = mp[a[i]];
    for (auto &t : query) {
        t.y = mp[t.y];
        assert(t.x1 < N);
        order[t.x1].pb(t.y);
        order[t.x2].pb(t.y);
    }
    for (int y : order[1])
        val[{1, y}] = 0;
    int x = 2;
    rf(i, 2, n) {
        if (a[i - 1] < a[i])
            update(a[i - 1], a[i], 1);
        else
            update(a[i], a[i - 1], 1);
        for (int y : order[x])
            val[{x, y}] = get_sum(y);
        x++;
    }
    for (auto t : query)
        cout << val[{t.x2, t.y}] - val[{t.x1, t.y}] << "\n";
    l.clear();
    mp.clear();
    val.clear();
    query.clear();
    rf(i, 1, N - 1) order[i].clear();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
        solve();
}