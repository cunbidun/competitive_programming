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

const int MOD = 998244353;
struct mint {
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) { // explicit -> don't silently convert to int
      v += MOD;
    }
  }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a) {
      if (p & 1) {
        ans *= a;
      }
    }
    return ans;
  }
  friend mint inv(const mint &a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
  mint &operator+=(const mint &m) {
    if ((v += m.v) >= MOD) {
      v -= MOD;
    }
    return *this;
  }
  mint &operator-=(const mint &m) {
    if ((v -= m.v) < 0) {
      v += MOD;
    }
    return *this;
  }
  mint &operator*=(const mint &m) {
    v = 1LL * v * m.v % MOD;
    return *this;
  }
  mint &operator/=(const mint &m) { return (*this) *= inv(m); }
  mint operator-() const { return mint(-v); }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
  friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
  friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
  friend mint operator+(mint a, const mint &b) { return a += b; }
  friend mint operator-(mint a, const mint &b) { return a -= b; }
  friend mint operator*(mint a, const mint &b) { return a *= b; }
  friend mint operator/(mint a, const mint &b) { return a /= b; }
};

// fenwick_tree
// 1-based index
template <typename T>
struct fenwick_tree {
  vector<T> bit;
  int n;
  fenwick_tree() {}
  fenwick_tree(int _n) { init(_n); }
  void init(int _n) {
    n = _n, bit.assign(n + 1, T{});
  }
  void update(int p, T v) {
    while (p <= n) {
      bit[p] += v, p += p & -p;
    }
  }
  T get(int p) {
    T res{};
    while (p >= 1) {
      res += bit[p], p -= p & -p;
    }
    return res;
  }
  T get(int l, int r) { return (l > r) ? T{} : get(r) - get(l - 1); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  struct portal {
    int x, y, s;
  };
  int N;
  cin >> N;
  fenwick_tree<mint> bit(N);

  vector<portal> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i].x >> a[i].y >> a[i].s;
  }
  vector<mint> f(N + 1);
  for (int i = 1; i <= N; i++) {
    int l = 1, r = i;
    while (l < r) {
      int m = (l + r) / 2;
      if (a[i].y <= a[m].x) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    f[i] += bit.get(l, i - 1);
    f[i] += a[i].x - a[i].y;
    bit.update(i, f[i]);
  }
  for (int i = 1; i <= N; i++) {
    f[i] += 1;
  }
  mint ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += a[i].x - a[i - 1].x - 1;
    if (a[i].s == 0) {
      ans += 1;
    } else {
      ans += f[i];
    }
  }
  cout << (ans + 1).v << '\n';
}
