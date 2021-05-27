#include <bits/stdc++.h>

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

 public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun>
decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
}  // namespace std

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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<long long> ans(N + 1);
    ans[N] = 1;
    dfs_tree T(N);
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      T.add_edge(u, v);
      ans[N] &= !((int)T.a[u].size() > 2);
      ans[N] &= !((int)T.a[v].size() > 2);
    }
    T.init_lca();
    auto mid = [&](int x, int y, int z) -> int {
      return T.dis(x, z) + T.dis(y, z) == T.dis(x, y);
    };
    int r = T.jump(1, T.lvl[1] - 1);
    int ls = N - T.c[r], rs = T.c[1];
    T.c[0] = ls;
    int s = 0;
    ans[1] = N - 1;
    for (int i : T.a[0]) {
      ans[0] += 1ll * (T.c[i] - 1) * T.c[i] / 2;
      ans[1] += 1ll * s * T.c[i];
      s += T.c[i];
    }
    ans[1] -= 1ll * ls * rs;
    int L = 0, R = 1;
    for (int i = 2; i < N; i++) {
      if (mid(L, R, i)) {
        continue;
      }
      if (mid(L, i, R)) {
        ans[i] = 1ll * ls * rs - 1ll * T.c[i] * T.c[L];
        R = i;
        rs = T.c[R];
      } else if (mid(i, R, L)) {
        ans[i] = 1ll * ls * rs - 1ll * T.c[i] * T.c[R];
        L = i;
        ls = T.c[L];
      } else {
        ans[i] = 1ll * ls * rs;
        break;
      }
    }
    for (long long i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
