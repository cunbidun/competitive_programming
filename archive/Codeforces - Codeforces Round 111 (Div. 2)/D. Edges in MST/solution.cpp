#include <array>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

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

using namespace std;
template <class c> struct rge { c b, e; };
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

struct dfs_tree_weighted {
public:
  vector<vector<int>> p;
  vector<vector<int>> mx;
  vector<vector<array<int, 2>>> a;
  vector<int> lvl, c;
  int n;
  dfs_tree_weighted() {}
  dfs_tree_weighted(int _n) { init(_n); }
  void init(int _n) {
    n = _n;
    lvl.assign(n, 0);
    c.assign(n, 0);
    p.assign(n, vector<int>(21));
    mx.assign(n, vector<int>(21));
    a.assign(n, vector<array<int, 2>>());
  }
  void add_edge(int u, int v, int w) {
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  void dfs(int u, int l = -1) {
    c[u] = 1;
    for (auto [v, w] : a[u]) {
      if (v != l) {
        p[v][0] = u;
        mx[v][0] = w;
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
        mx[i][j] = max(mx[i][j - 1], mx[p[i][j - 1]][j - 1]);
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

  int jump_mx(int x, int l) {
    int ans = 0;
    for (int i = 19; i >= 0; i--) {
      if ((l >> i) & 1) {
        ans = max(ans, mx[x][i]);
        x = p[x][i];
      }
    }
    return ans;
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
  int get_mx(int x, int y) {
    int z = lca(x, y);
    return max(jump_mx(x, lvl[x] - lvl[z]), jump_mx(y, lvl[y] - lvl[z]));
  }
};

template <typename T> struct segment_tree {
  int n;
  vector<T> st;
  segment_tree(int _n) : n(_n) { st.assign(4 * n, 1e9); }
  void update(int i, int l, int r, int p, T v) {
    if (r < p || p < l) {
      return;
    }
    if (p == l && r == p) {
      st[i] = v;
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, p, v);
    update(i * 2 + 2, m + 1, r, p, v);
    st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
  }
  T get_min(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return 1e9;
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return min(get_min(i * 2 + 1, l, m, ql, qr), get_min(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) { update(0, 0, n - 1, p, v); }
  T get_min(int L, int R) { return get_min(0, 0, n - 1, L, R); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<array<int, 4>> edges, mst, remains, atleast;
  vector<int> ans(M);
  for (int i = 0; i < M; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    edges.push_back({u, v, w, i});
  }

  sort(edges.begin(), edges.end(), [](auto a, auto b) { return a[2] < b[2]; });
  union_find dsu(N);
  dfs_tree_weighted T(N);
  for (int i = 0; i < M; i++) {
    auto [u, v, w, id] = edges[i];
    if (!dsu.is_same_set(u, v)) {
      T.add_edge(u, v, w);
      dsu.merge(u, v);
      mst.push_back(edges[i]);
    } else {
      remains.push_back(edges[i]);
    }
  }

  T.init_lca();

  for (int i = 0; i < (int)remains.size(); i++) {
    auto [u, v, w, id] = remains[i];
    if (T.get_mx(u, v) == w) {
      atleast.push_back(remains[i]);
      ans[id] = 1;
    } else {
      ans[id] = 2;
    }
  }

  sort(mst.begin(), mst.end(), [](auto a, auto b) { return a[2] > b[2]; });
  sort(atleast.begin(), atleast.end(), [](auto a, auto b) { return a[2] > b[2]; });

  // debug() << imie(mst);

  vector<int> discover(N);
  vector<int> finish(N);
  int time = 0;
  yc([&](auto dfs, int u, int l) -> void {
    discover[u] = time;
    for (auto [v, w] : T.a[u]) {
      if (v != l) {
        time++;
        dfs(v, u);
      }
    }
    finish[u] = time;
  })(0, 0);

  int p = 0;
  vector<int> clean_up;
  atleast.push_back({0, 0, 0, 0});
  mst.push_back({0, 0, 0, 0});
  segment_tree<int> st(time + 1);

  for (int i = 0; i < (int)atleast.size() - 1; i++) {
    auto [u, v, w, id] = atleast[i];
    int lca = T.lca(u, v);
    st.update(discover[u], T.lvl[lca]);
    st.update(discover[v], T.lvl[lca]);
    clean_up.push_back(discover[u]);
    clean_up.push_back(discover[v]);
    if (w != atleast[i + 1][2]) {
      while (p < N - 1) {
        if (mst[p][2] != w) {
          p++;
        } else {
          break;
        }
      }
      while (p < N - 1) {
        auto [mu, mv, mw, mid] = mst[p];
        if (T.lvl[mu] > T.lvl[mv]) {
          swap(mu, mv);
        }
        int mn = st.get_min(discover[mv], finish[mv]);
        if (mn < T.lvl[mv]) {
          ans[mid] = 1;
        }
        if (mst[p][2] != mst[p + 1][2]) {
          break;
        }
        p++;
      }
      for (int _ : clean_up) {
        st.update(_, 1e9);
      }
      clean_up.clear();
    }
  }

  for (int i = 0; i < M; i++) {
    if (ans[i] == 0) {
      cout << "any\n";
    } else if (ans[i] == 1) {
      cout << "at least one\n";
    } else {
      cout << "none\n";
    }
  }
}
