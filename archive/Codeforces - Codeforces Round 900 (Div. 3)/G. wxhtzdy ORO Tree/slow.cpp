#include <bits/stdc++.h>

#define f first
#define s second
using namespace std;
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
#define int long long
const int maxn = 2e5 + 69;
const int k = 19;
const int bits = 30;
vector<int> g[maxn];
int n, q, a[maxn], up[maxn][k], tin[maxn], tout[maxn], timer, d[maxn];
int r[maxn][k];
int bst[maxn][bits];
void dfs(int v, int p, vector<int> b) {
  tin[v] = ++timer;
  up[v][0] = p;
  r[v][0] = a[p];
  d[v] = d[p] + 1;
  for (int i = 0; i < bits; i++) {
    bst[v][i] = b[i];
    if (a[v] & (1 << i))
      b[i] = v;
  }
  for (int i = 1; i < k; i++) {
    up[v][i] = up[up[v][i - 1]][i - 1];
    r[v][i] = r[v][i - 1] | r[up[v][i - 1]][i - 1];
  }
  for (auto u : g[v]) {
    if (u != p)
      dfs(u, v, b);
  }
  tout[v] = timer;
}

bool is_anc(int u, int v) { return tin[u] <= tin[v] && tout[u] >= tout[v]; }

int lca(int u, int v) {
  if (is_anc(u, v))
    return u;
  else if (is_anc(v, u))
    return v;
  for (int i = k - 1; i >= 0; i--) {
    if (!is_anc(up[u][i], v) && up[u][i] > 0)
      u = up[u][i];
  }
  return up[u][0];
}

int OR(int u, int dis) {
  int res = a[u];
  for (int j = 0; j < bits; j++) {
    if (dis & (1 << j)) {
      res |= r[u][j];
      u = up[u][j];
    }
  }
  return res;
}

int Qry(int u, int v) {
  int lc = lca(u, v);
  return OR(u, d[u] - d[lc]) | OR(v, d[v] - d[lc]);
}

signed main() {
  int tt = 1;
  cin >> tt;
  while (tt--) {
    cin >> n;
    timer = 0;
    for (int i = 1; i <= n; i++)
      g[i].clear();
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n - 1; i++) {
      int x, y;
      cin >> x >> y;
      g[x].push_back(y);
      g[y].push_back(x);
    }
    vector<int> temp(30, -1);
    dfs(1, 0, temp);
    cin >> q;
    for (int i = 1; i <= q; i++) {
      int x, y;
      cin >> x >> y;
      int LCA = lca(x, y);
      vector<int> t;
      t.push_back(x);
      t.push_back(y);
      for (int i = 0; i < bits; i++) {
        if (bst[x][i] != -1 && is_anc(LCA, bst[x][i]))
          t.push_back(bst[x][i]);
        if (bst[y][i] != -1 && is_anc(LCA, bst[y][i]))
          t.push_back(bst[y][i]);
      }
      // debug() << imie(t);
      int ans = __builtin_popcount(a[x]) + __builtin_popcount(a[y]);
      for (auto p : t) {
        int x1 = a[x], x2 = a[y];
        x1 |= Qry(x, p);
        x2 |= Qry(y, p);
        ans = max(ans, 1ll * __builtin_popcount(x1) + __builtin_popcount(x2));
      }
      cout << ans << " ";
    }
    cout << "\n";
  }
  return 0;
}
