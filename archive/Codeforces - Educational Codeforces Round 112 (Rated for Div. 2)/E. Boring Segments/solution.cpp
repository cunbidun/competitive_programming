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
struct segtree_rsum_rmin {
  int n;
  vector<T> st, lazy;
  segtree_rsum_rmin(int _n) : n(_n) {
    st.assign(8 * n, T{});
    lazy.assign(8 * n, T{});
  }
  void lazy_prop(int i, int l, int r) {
    if (lazy[i] != 0) {
      st[i] += lazy[i];
      if (l != r) {
        lazy[i * 2 + 1] += lazy[i];
        lazy[i * 2 + 2] += lazy[i];
      }
    }
    lazy[i] = 0;
  }

  void update(int i, int l, int r, int ql, int qr, T v) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l) {
      return;
    }
    if (ql <= l && r <= qr) {
      lazy[i] += v;
      lazy_prop(i, l, r);
      return;
    }
    int m = (l + r) / 2;
    update(i * 2 + 1, l, m, ql, qr, v);
    update(i * 2 + 2, m + 1, r, ql, qr, v);
    st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
  }

  T get_min(int i, int l, int r, int ql, int qr) {
    lazy_prop(i, l, r);
    if (r < ql || qr < l || qr < ql) {
      return numeric_limits<long long>::max();
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    return min(get_min(i * 2 + 1, l, m, ql, qr), get_min(i * 2 + 2, m + 1, r, ql, qr));
  }
  void update(int l, int r, T v) {
    update(0, 0, n - 1, l, r, v);
  }
  T get_min(int l, int r) {
    return get_min(0, 0, n - 1, l, r);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<array<int, 3>> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    a[i][1] -= 1;
  }
  segtree_rsum_rmin<long long> st(M);
  sort(a.begin(), a.end(), [](auto a, auto b) { return a[2] < b[2]; });
  int p = 0;
  int ans = 1e9;
  for (int i = 0; i < N; i++) {
    st.update(a[i][0], a[i][1], 1);
    while (st.get_min(1, M - 1) != 0) {
      ans = min(ans, a[i][2] - a[p][2]);
      st.update(a[p][0], a[p][1], -1);
      p++;
    }
  }
  cout << ans << '\n';
}
