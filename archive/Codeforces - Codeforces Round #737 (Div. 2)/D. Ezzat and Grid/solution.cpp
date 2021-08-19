#include <bits/stdc++.h>

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

// 0-indexed
template <typename T>
struct segtree_rset_rmax {
  int n;
  vector<pair<T, int>> st, lazy;
  segtree_rset_rmax(int _n) : n(_n) {
    st = lazy = vector<pair<T, int>>(4 * n, {T{}, 0});
  }
  void lazy_prop(int i, int l, int r) {
    if (lazy[i].first != 0) {
      st[i] = lazy[i];
      if (l != r) {
        lazy[i * 2 + 1] = lazy[i];
        lazy[i * 2 + 2] = lazy[i];
      }
    }
    lazy[i].first = 0;
  }

  void update(int i, int l, int r, int ql, int qr, T v, int id) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i] = {v, id};
      lazy_prop(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, v, id);
    update(i * 2 + 2, m + 1, r, ql, qr, v, id);
    st[i] = max(st[i * 2 + 1], st[i * 2 + 2]);
  }

  pair<T, int> get_max(int i, int l, int r, int ql, int qr) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return {numeric_limits<T>::min(), 0};
    }
    if (ql <= l && r <= qr) {
      return {st[i].first, st[i].second};
    }
    int m = (l + r) / 2;
    return max(get_max(i * 2 + 1, l, m, ql, qr), get_max(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int l, int r, T v, int id) {
    update(0, 0, n - 1, l, r, v, id);
  }
  pair<T, int> get_max(int l, int r) {
    return get_max(0, 0, n - 1, l, r);
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<array<int, 2>>> a(N + 1);
  compressor<int> c;
  for (int i = 0; i < M; i++) {
    int id, l, r;
    cin >> id >> l >> r;
    c.add(l);
    c.add(r);
    a[id].push_back({l, r});
  }
  c.compress();
  int mx = 0;
  for (int i = 1; i <= N; i++) {
    for (auto &p : a[i]) {
      p[0] = c.get(p[0]);
      p[1] = c.get(p[1]);
      mx = max(mx, p[1]);
    }
  }
  segtree_rset_rmax<int> st(mx + 5);
  vector<int> trace(N + 1);
  int ans = 0;
  int last = 0;
  for (int i = 1; i <= N; i++) {
    mx = 0;
    int pos = 0;
    for (auto p : a[i]) {
      auto tmp = st.get_max(p[0], p[1]);
      if (mx < tmp.first) {
        pos = tmp.second;
        mx = tmp.first;
      }
    }
    trace[i] = pos;
    if (ans < mx + 1) {
      last = i;
      ans = mx + 1;
    }
    for (auto p : a[i]) {
      st.update(p[0], p[1], mx + 1, i);
    }
  }
  set<int> s;
  while (last != 0) {
    s.insert(last);
    last = trace[last];
  }
  vector<int> l;
  for (int i = 1; i <= N; i++) {
    if (s.find(i) == s.end()) {
      l.push_back(i);
    }
  }
  cout << l.size() << '\n';
  for (int i : l) {
    cout << i << ' ';
  }
  cout << '\n';
}
