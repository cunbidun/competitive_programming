/**
 *  author: cunbidun
 *  created: Thursday, 2023-08-10 18:31:39 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

template <typename T> T mod_inv(T a, T m) {
  // assert(__gcd(a, m) == 1);
  a %= m;
  a = a < 0 ? a + m : a;
  T x = a, y = m, vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x, vy -= k * vx;
    swap(x, y), swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}

template <int MOD> struct mint {
private:
  int v;
  explicit operator int() const { return v; }

public:
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) { // explicit -> don't silently convert to int
      v += MOD;
    }
  }
  friend std::ostream &operator<<(std::ostream &out, const mint &n) { return out << int(n); }
  friend std::istream &operator>>(std::istream &in, mint &n) {
    long long v_;
    in >> v_;
    n = mint(v_);
    return in;
  }
  mint pow(long long p) const {
    assert(p >= 0);
    mint res = 1, a = v;
    assert(p >= 0);
    for (; p; p /= 2, a *= a) {
      if (p & 1) {
        res *= a;
      }
    }
    return res;
  }
  mint inv() const {
    mint res;
    res.v = mod_inv(v, MOD);
    return res;
  }
  friend mint inv(const mint &a) { return a.inv(); }
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
  mint &operator/=(const mint &m) { return (*this) *= m.inv(); }
  mint operator-() const { return mint(-v); }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  mint operator++(int) {
    mint result = *this;
    ++*this;
    return result;
  }
  mint operator--(int) {
    mint result = *this;
    --*this;
    return result;
  }
  friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
  friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
  friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
  friend mint operator+(mint a, const mint &b) { return a += b; }
  friend mint operator-(mint a, const mint &b) { return a -= b; }
  friend mint operator*(mint a, const mint &b) { return a *= b; }
  friend mint operator/(mint a, const mint &b) { return a /= b; }
};

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  using mint = mint<998244353>;
  int K;
  cin >> K;
  int N = (1 << K);
  vector<mint> f(N + 1);
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    f[i] = f[i - 1] * i;
  }
  vector<int> p(N + 1);
  vector<int> taken(2 * N);
  for (int i = 1; i <= N; i++) {
    int x;
    cin >> x;
    if (x != -1) {
      int current = i + N - 1;
      while (current) {
        taken[current]++;
        current /= 2;
      }
      p[x] = i;
    }
  }
  mint ans = 1;
  for (int i = K - 1; i >= 0; i--) {
    int num_block = 1 << i;
    int free = 1 << i;
    int block_size = N / num_block;

    set<int> used;

    int start = num_block;
    // cout << i << ' ' << (1 << i) + 1 << ' ' << (1 << (i + 1)) << '\n';
    // cout << start << ' ' << num_block << ' ' << block_size << '\n';
    for (int j = (1 << i) + 1; j <= (1 << (i + 1)); j++) {
      if (p[j] != 0) {
        free--;
        int block_id = start - 1 + (p[j] + block_size - 1) / block_size;
        if (used.find(block_id) != used.end()) {
          cout << 0 << '\n';
          return 0;
        }
        used.insert(block_id);
      }
    }
    mint res = f[free];
    // debug() << imie(free);
    // cout << i << ' ' << (1 << i) + 1 << ' ' << (1 << (i + 1)) << ' ' << free << '\n';

    for (int j = 1; j <= N; j += block_size) {
      int block_id = start - 1 + (j + block_size - 1) / block_size;
      if (used.find(block_id) == used.end()) {
        // cout << i << ' ' << j << ' ' << block_id << ' ' << block_size - taken[block_id] << '\n';
        res *= block_size - taken[block_id];
        int current = block_id;
        while (current) {
          taken[current]++;
          current /= 2;
        }
      }
    }
    // cout << res << '\n';
    ans *= res;
    // cout << "====================================================\n";
  }
  cout << ans << '\n';
}
