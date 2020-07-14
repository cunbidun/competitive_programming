#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
#define watch(x) cout << (#x) << " = " << (x) << endl
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

struct UnionFind {
    vi p, size, rank;
    int dsuSize;

    UnionFind(int N) {
        dsuSize = N;
        p.assign(N + 1, 0);
        rank.assign(N + 1, 0);
        size.assign(N + 1, 0);
        for (int i = 1; i <= N; i++) {
            p[i] = i;
            size[i] = 1;
        }
    }

    int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }

    bool isSameSet(int x, int y) { return find(x) == find(y); }

    void merge(int x, int y) {
        if (!isSameSet(x, y)) {
            dsuSize--;
            x = find(x);
            y = find(y);
            if (rank[x] > rank[y]) {
                size[x] += size[y];
                p[y] = x;
            } else {
                p[x] = y;
                size[y] += size[x];
                if (rank[x] == rank[y])
                    rank[y]++;
            }
        }
    }

    int getSize(int i) { return size[find(i)]; }

    int getDsuSize() { return dsuSize; }
};

int lmc(int a, int b) { return a * b / __gcd(a, b); }

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vi a(n + 1), cnt(n + 1);
    bool f = 0;
    UnionFind dsu(n);
    rf(i, 1, n) {
        cin >> a[i];
        dsu.merge(i, a[i]);
        cnt[a[i]]++;
        if (cnt[a[i]] >= 2) {
            f = 1;
        }
    }
    if (f)
        return cout << "-1\n", 0;
    int ans = 1;
    rf(i, 1, n) {
        if (dsu.getSize(i) % 2 == 0)
            ans = lcm(ans, dsu.getSize(i) / 2);
        else
            ans = lcm(ans, dsu.getSize(i));
        // cout << dsu.getSize(i) << "\n";
    }
    cout << ans << "\n";
}