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
    vector<int> a(N + 1);
    vector<vector<int>> g(N + 1);
    dfs_tree t(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      g[u].push_back(v);
      g[v].push_back(u);
      t.add_edge(u, v);
    }

    vector<vector<int>> sig(N + 1);
    vector<int> lvl(N + 1);
    lvl[1] = 1;

    yc([&](auto dfs, int u, int l) -> void {
      for (int v : g[u]) {
        if (v != l) {
          lvl[v] = lvl[u] + 1;
          sig[v].push_back(v);
          int current = a[v];
          for (int su : sig[u]) {
            if ((current | a[su]) > current) {
              sig[v].push_back(su);
              current |= a[su];
            }
          }
          dfs(v, u);
        }
      }
    })(1, 1);

    // debug() << imie(sig[4]);
    // debug() << imie(sig[7]);

    t.init_lca(1);

    vector<vector<int>> p_or(N + 1, vector<int>(21));
    for (int i = 1; i <= N; i++) {
      p_or[i][0] = a[i] | a[t.p[i][0]];
    }

    for (int j = 1; j <= 20; j++) {
      for (int i = 1; i <= N; i++) {
        p_or[i][j] = p_or[i][j - 1] | p_or[t.p[i][j - 1]][j - 1];
      }
    }

    auto OR = [&](int u, int dis) {
      int res = a[u];
      for (int i = 19; i >= 0; i--) {
        if ((dis >> i) & 1) {
          res |= p_or[u][i];
          u = t.p[u][i];
        }
      }
      return res;
    };

    auto qry = [&](int u, int v, int lca = -1) {
      if (lca == -1) {
        lca = t.lca(u, v);
      }
      return OR(u, t.lvl[u] - t.lvl[lca]) | OR(v, t.lvl[v] - t.lvl[lca]);
    };

    int Q;
    cin >> Q;
    while (Q--) {
      int u, v;
      cin >> u >> v;
      int lca = t.lca(u, v);
      vector<int> i_u, i_v;
      for (int i : sig[u]) {
        if (lvl[i] > lvl[lca]) {
          i_u.push_back(i);
        }
      }
      i_u.push_back(lca);
      for (int i : sig[v]) {
        if (lvl[i] > lvl[lca]) {
          i_v.push_back(i);
        }
      }
      reverse(i_v.begin(), i_v.end());
      for (int i : i_v) {
        i_u.push_back(i);
      }
      int ans = 0;
      debug() << imie(i_u);
      for (int i : i_u) {
        auto xu = qry(u, i);
        auto xv = qry(i, v);
        // cout << i << ' ' << xu << ' ' << xv << '\n';
        ans = max(ans, __builtin_popcount(xu) + __builtin_popcount(xv));
      }
      cout << ans << ' ';
    }
    cout << '\n';
  }
}
