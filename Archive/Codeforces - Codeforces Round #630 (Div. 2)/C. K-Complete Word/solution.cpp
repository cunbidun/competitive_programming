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
void solve() {
    int n, k;
    cin >> n >> k;
    UnionFind dsu(n);
    vector<char> a(n + 1);
    rf(i, 1, n) cin >> a[i];
    set<int> p[n + 1];
    vi ch(n + 1);
    rf(i, 1, n) if (!ch[i]) {
        for (int j = i; j <= n; j += k) {
            ch[j] = 1;
            ch[n - j + 1] = 1;
            dsu.merge(i, n - j + 1);
            dsu.merge(i, j);
        }
    }
    rf(i, 1, n) 
        p[dsu.find(i)].insert(i);
    
    int ans = 0;
    rf(i, 1, n) {
        vi cnt(26);
        int mx = 0;
        for (int in : p[i]) {
            cnt[a[in] - 'a']++;
            mx = max(mx, cnt[a[in] - 'a']);
        }
        ans += sz(p[i]) - mx;
    }
    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}