#include <bits/stdc++.h>

using namespace std;

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

template <class c> struct rge {
  c b, e;
};
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

struct dfs_tree {
public:
  vector<vector<int>> p;
  vector<vector<int>> a;
  vector<int> lvl, c;
  vector<array<int, 2>> edges;
  int n;
  dfs_tree() {}
  dfs_tree(int _n) { init(_n); }
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
    edges.push_back({u, v});
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
    vector<vector<int>> a(N + 1);
    dfs_tree tree(N + 1);

    for (int i = 1; i < N; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
      tree.add_edge(u, v);
    }

    int K;
    cin >> K;
    vector<array<int, 2>> path;
    for (int i = 0; i < K; i++) {
      int u, v;
      cin >> u >> v;
      path.push_back({u, v});
    }

    vector<int> in(N + 1), out(N + 1);
    int time = 0;
    yc([&](auto dfs, int u, int l) -> void {
      time += 1;
      in[u] = time;
      for (int v : a[u]) {
        if (v != l) {
          dfs(v, u);
        }
      }
      time += 1;
      out[u] = time;
    })(1, 1);
    auto inside = [&](int x, int y) -> bool { return in[y] <= in[x] && out[x] <= out[y]; };

    set<int> value;
    tree.init_lca(1);

    // for each edge in the tree and for every pair of input paths, check if the edge is in the path.
    for (int i = 0; i < (int)tree.edges.size(); i++) {
      auto [u, v] = tree.edges[i];
      int mask = 0;
      for (int j = 0; j < K; j++) {
        auto [p1, p2] = path[j];
        int lca = tree.lca(p1, p2);
        if (inside(u, lca) && inside(v, lca) && inside(p1, u) && inside(p1, v)) {
          mask += (1 << j);
        }
        if (inside(u, lca) && inside(v, lca) && inside(p2, u) && inside(p2, v)) {
          mask += (1 << j);
        }
      }
      value.insert(mask);
    }

    // f[mask] = the minimun number of edges need to cover the corresponding set of pair
    // answer = f[111...111]: all paths are covered
    vector<int> f(1 << K, 1e9);
    f[0] = 0;

    // the trick here is the size of value is O(k), so the time complexity for the next nested for loop
    // will be O(K * 2^K)
    for (int i = 0; i < (1 << K); i++) {
      for (int j : value) {
        f[i | j] = min(f[i | j], f[i] + 1);
      }
    }
    cout << f[(1 << K) - 1] << '\n';
  }
}
