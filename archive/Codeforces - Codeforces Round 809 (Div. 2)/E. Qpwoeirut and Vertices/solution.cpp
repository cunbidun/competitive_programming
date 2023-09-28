/**
 *  author: cunbidun
 *  created: Wednesday, 2023-09-20 22:40:54 CDT
 **/
#include <array>
#include <assert.h>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct union_find {
  typedef vector<int> vi;
  vi p, sz, rank;
  int dsu_size;
  union_find(int _n) : p(vi(_n)), sz(vi(_n, 1)), rank(vi(_n)), dsu_size(_n) {
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }
  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool is_same_set(int x, int y) { return find(x) == find(y); }
  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x), y = find(y);
      if (rank[x] > rank[y]) {
        p[y] = x, sz[x] += sz[y];
      } else {
        p[x] = y, sz[y] += sz[x];
        rank[y] += (rank[x] == rank[y]);
      }
    }
  }
  int size(int i) { return sz[find(i)]; }
};

struct dfs_tree {
public:
  vector<vector<array<int, 2>>> p;
  vector<vector<array<int, 2>>> a;
  vector<int> lvl;
  int n;
  dfs_tree() {}
  dfs_tree(int _n) { init(_n); }
  void init(int _n) {
    n = _n;
    lvl.assign(n, 0);
    p.assign(n, vector<array<int, 2>>(21));
    a.assign(n, vector<array<int, 2>>());
  }
  void add_edge(int u, int v, int w) {
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  void dfs(int u, int l = -1) {
    for (auto [v, w] : a[u]) {
      if (v != l) {
        p[v][0][0] = u;
        p[v][0][1] = w;
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
      }
    }
  }
  void init_lca(int r = 0) {
    dfs(r);
    for (int j = 1; j <= 20; j++) {
      for (int i = 0; i < n; i++) {
        p[i][j][0] = p[p[i][j - 1][0]][j - 1][0];
        p[i][j][1] = max(p[i][j - 1][1], p[p[i][j - 1][0]][j - 1][1]);
      }
    }
  }
  array<int, 2> jump(int x, int l) {
    int mx = 0;
    for (int i = 19; i >= 0; i--) {
      if ((l >> i) & 1) {
        mx = max(mx, p[x][i][1]);
        x = p[x][i][0];
      }
    }
    return {x, mx};
  }
  array<int, 2> lca(int x, int y) {
    int mx = 0;
    if (lvl[x] > lvl[y]) {
      swap(x, y);
    }

    auto e = jump(y, lvl[y] - lvl[x]);
    y = e[0];
    mx = e[1];

    if (x == y) {
      return {x, mx};
    }
    for (int i = 19; i >= 0; i--) {
      if (p[y][i][0] != p[x][i][0]) {
        mx = max({mx, p[x][i][1], p[y][i][1]});
        x = p[x][i][0];
        y = p[y][i][0];
      }
    }
    mx = max({mx, p[x][0][1], p[y][0][1]});
    return {p[x][0][0], mx};
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<int> ans;
  while (T--) {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<array<int, 3>> edges;
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      edges.push_back({u, v, i + 1});
    }
    union_find dsu(N);
    dfs_tree g(N);
    for (auto [u, v, i] : edges) {
      if (!dsu.is_same_set(u, v)) {
        dsu.merge(u, v);
        g.add_edge(u, v, i);
      }
    }
    g.init_lca(0);
    g.lca(1, 2);

    vector<vector<int>> st(N, vector<int>(19, 0));
    for (int j = 1; j <= 18; j++) {
      for (int i = 0; i + (1 << (j - 1)) < N; i++) {
        st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        st[i][j] = max(st[i][j], g.lca(i, i + (1 << (j - 1)))[1]);
      }
    }
    // cout << st[1][1] << '\n';
    auto rmq = [&](int l, int r) -> long long {
      int k = 32 - __builtin_clz(r - l + 1) - 1;
      return max({st[l][k], st[r - (1 << k) + 1][k], g.lca(l, r - (1 << k) + 1)[1]});
    };

    vector<array<int, 2>> tmp;
    while (Q--) {
      int l, r;
      cin >> l >> r;
      tmp.push_back({l, r});
      l--, r--;
      cout << rmq(l, r) << ' ';
    }
    cout << '\n';
  }
}
