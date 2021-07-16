#include <bits/stdc++.h>

using namespace std;

struct dfs_tree {
public:
  vector<vector<int>> p;
  vector<vector<int>> a;
  vector<int> lvl, c;
  int n;
  dfs_tree() {}
  dfs_tree(int _n) {
    init(_n);
  }
  void init(int _n) {
    n = _n;
    lvl.assign(n, 0);
    c.assign(n, 0);
    p.assign(n, vector<int>(21));
    a.assign(n, vector<int>());
  }
  void add_edge(int u, int v) {
    a[u].push_back(v);
    a[v].push_back(u);
  }
  void dfs(int u, int l = -1) {
    c[u] = 1;
    for (int v : a[u]) {
      if (v != l) {
        p[v][0] = u;
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
        c[u] += c[v];
      }
    }
  }
  void init_lca(int r = 0) {
    dfs(r);
    for (int j = 1; j <= 20; j++) {
      for (int i = 0; i < n; i++) {
        p[i][j] = p[p[i][j - 1]][j - 1];
      }
    }
  }
  int jump(int x, int l) {
    for (int i = 19; i >= 0; i--) {
      if ((l >> i) & 1) {
        x = p[x][i];
      }
    }
    return x;
  }
  int lca(int x, int y) {
    if (lvl[x] > lvl[y]) {
      swap(x, y);
    }
    y = jump(y, lvl[y] - lvl[x]);
    if (x == y) {
      return x;
    }
    for (int i = 19; i >= 0; i--) {
      if (p[y][i] != p[x][i]) {
        x = p[x][i];
        y = p[y][i];
      }
    }
    return p[x][0];
  }
  int dis(int x, int y) {
    int z = lca(x, y);
    return lvl[x] + lvl[y] - 2 * lvl[z];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  dfs_tree T;
  T.init(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    T.add_edge(u - 1, v - 1);
  }
  T.init_lca(0);
  while (Q--) {
    int c, d;
    cin >> c >> d;
    c--, d--;
    cout << ((T.dis(c, d) % 2 == 1) ? "Road" : "Town") << '\n';
  }
}
