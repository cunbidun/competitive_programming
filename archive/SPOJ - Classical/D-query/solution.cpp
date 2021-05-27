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

const int SQRT = 750;

struct Query {
    int l, r, id;
} query[(int)2e5 + 1];

bool cmp(Query a, Query b) {
    if (a.l / SQRT != b.l / SQRT)
        return a.l / SQRT < b.l / SQRT;
    return a.r < b.r;
}

int n, q, ans = 0;
int curL = 0, curR = 0;
vi cnt(1e6 + 1), a(3e4 + 1), answer(2e5 + 1);

vi l;
map<int, int> mp;
void compress() {
    sort(all(l));
    l.resize(distance(l.begin(), unique(all(l))));
    for (int i : l)
        mp[i] = sz(mp) + 1;
}

void add(int p) {
    cnt[a[p]]++;
    if (cnt[a[p]] == 1)
        ans++;
}

void remove(int p) {
    cnt[a[p]]--;
    if (cnt[a[p]] == 0)
        ans--;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    rf(i, 1, n) cin >> a[i], l.pb(a[i]);
    compress();
    rf(i, 1, n) a[i] = mp[a[i]];

    cin >> q;
    rf(i, 1, q) {
        int l, r;
        cin >> l >> r;
        query[i].id = i;
        query[i].l = l;
        query[i].r = r;
    }
    sort(query + 1, query + q + 1, cmp);
    rf(i, 1, q) {
        while (curL < query[i].l)
            remove(curL++);
        while (curL > query[i].l)
            add(--curL);
        while (curR < query[i].r)
            add(++curR);
        while (curR > query[i].r)
            remove(curR--);
        answer[query[i].id] = ans;
    }
    rf(i, 1, q) cout << answer[i] << "\n";
}
