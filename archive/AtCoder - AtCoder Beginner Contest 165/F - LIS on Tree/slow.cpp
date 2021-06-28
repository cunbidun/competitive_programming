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
} // namespace std

using namespace std;

template <class c>
struct rge { c b, e; };
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c>
  debug &operator<<(const c &) { return *this; }
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

template <class T>
struct compressor {
public:
  vector<T> l;
  map<T, int> mp;
  compressor() {}
  void add(T x) {
    l.push_back(x);
  }
  void compress() {
    sort(l.begin(), l.end());
    l.resize(distance(l.begin(), unique(l.begin(), l.end())));
    for (int i : l)
      mp[i] = (int)mp.size() + 1;
  }
  int get(T x) {
    return mp[x];
  }
  int size() {
    return (int)mp.size();
  }
};

template <typename T>
struct segment_tree {
  int n;
  vector<T> st, lazy;
  segment_tree(int _n) : n(_n) {
    st.assign(8 * n, 0);
  }
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
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }
  T get_max(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return -1e9;
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int p, T v) {
    update(0, 0, n - 1, p, v);
  }
  T get_max(int L, int R) {
    return get_max(0, 0, n - 1, L, R);
  }
};

// Binary search (note boundaries in the caller)
int CeilIndex(std::vector<int> &v, int l, int r, int key) {
  while (r - l > 1) {
    int m = l + (r - l) / 2;
    if (v[m] >= key)
      r = m;
    else
      l = m;
  }

  return r;
}

int LongestIncreasingSubsequenceLength(std::vector<int> &v) {
  if (v.size() == 0)
    return 0;

  std::vector<int> tail(v.size(), 0);
  int length = 1; // always points empty slot in tail

  tail[0] = v[0];
  for (size_t i = 1; i < v.size(); i++) {

    // new smallest value
    if (v[i] < tail[0])
      tail[0] = v[i];

    // v[i] extends largest subsequence
    else if (v[i] > tail[length - 1])
      tail[length++] = v[i];

    // v[i] will become end candidate of an existing
    // subsequence or Throw away larger elements in all
    // LIS, to make room for upcoming grater elements
    // than v[i] (and also, v[i] would have already
    // appeared in one of LIS, identify the location
    // and replace it)
    else
      tail[CeilIndex(tail, -1, length - 1, v[i])] = v[i];
  }

  return length;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  dfs_tree T;
  T.init(N);
  segment_tree<int> st(N);
  compressor<int> c;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
    c.add(a[i]);
  }
  c.compress();
  for (int i = 0; i < N; i++) {
    a[i] = c.get(a[i]);
  }
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    T.add_edge(u - 1, v - 1);
  }
  vector<int> list;
  vector<int> ans(N);
  yc([&](auto dfs, int u, int l) -> void {
    list.push_back(a[u]);
    ans[u] = LongestIncreasingSubsequenceLength(list);
    for (int v : T.a[u]) {
      if (v != l) {
        dfs(v, u);
      }
    }
    list.pop_back();
  })(0, 0);
  for (int i : ans) {
    cout << i << '\n';
  }
}
