/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-17 21:59:59 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> struct segment_tree {
  int n;
  struct node {
    T mx;
    int pos;
  };
  vector<node> st;
  segment_tree(int _n) : n(_n) { st.assign(4 * n, {}); }
  void build(int i, int l, int r, vector<T> &a) {
    if (l == r) {
      st[i] = {a[l], l};
      return;
    }
    int m = (l + r) / 2;
    build(i * 2 + 1, l, m, a);
    build(i * 2 + 2, m + 1, r, a);
    if (st[i * 2 + 1].mx < st[i * 2 + 2].mx) {
      st[i] = st[i * 2 + 2];
    } else {
      st[i] = st[i * 2 + 1];
    }
  }
  node get_max(int i, int l, int r, int ql, int qr) {
    if (r < ql || qr < l || qr < ql) {
      return {0, 0};
    }
    if (ql <= l && r <= qr) {
      return st[i];
    }
    int m = (l + r) / 2;
    auto l_side = get_max(i * 2 + 1, l, m, ql, qr);
    auto r_side = get_max(i * 2 + 2, m + 1, r, ql, qr);
    if (l_side.mx < r_side.mx) {
      return r_side;
    } else {
      return l_side;
    }
  }
  node get_max(int L, int R) {
    assert(L <= R);
    return get_max(0, 0, n - 1, L, R);
  }
};

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
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    using mint = mint<1000000007>;
    vector<int> a(N);
    segment_tree<int> st(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    st.build(0, 0, N - 1, a);
    vector<vector<mint>> f(N, vector<mint>(M + 1));
    vector<vector<mint>> g(N, vector<mint>(M + 1));
    vector<vector<bool>> v_f(N, vector<bool>(M + 1));
    vector<vector<bool>> v_g(N, vector<bool>(M + 1));

    auto e = st.get_max(0, N - 1);

    auto solve = yc([&](auto _solve, int c, int val, int L, int R, int type) -> mint {
      if (val == 0) {
        return 0;
      }
      if (type == 0) {
        if (v_f[c][val]) {
          return f[c][val];
        }
        v_f[c][val] = 1;

        if (L == R) {
          assert(c == L);
          f[c][val] = 1;
        } else {
          mint l_side = 1, r_side = 1;
          if (c != L) {
            auto l = st.get_max(L, c - 1);
            l_side = _solve(l.pos, val - 1, L, c - 1, 1);
          }
          if (c != R) {
            auto r = st.get_max(c + 1, R);
            r_side = _solve(r.pos, val, c + 1, R, 1);
          }
          f[c][val] = l_side * r_side;
        }
        return f[c][val];
      } else {
        if (v_g[c][val]) {
          return g[c][val];
        }
        v_g[c][val] = 1;
        return g[c][val] = _solve(c, val - 1, L, R, 1) + _solve(c, val, L, R, 0);
      }
    });
    cout << solve(e.pos, M, 0, N - 1, 1) << '\n';
  }
}
