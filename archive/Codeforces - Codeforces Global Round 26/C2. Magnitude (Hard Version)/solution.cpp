#include <bits/stdc++.h>

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
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using mint = mint<998244353>;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    using ll = long long;
    vector<ll> f_max(N + 1);
    vector<ll> f_min(N + 1, 1e18);
    f_min[0] = 0;
    vector<mint> count_max(N + 1);
    vector<mint> count_min(N + 1);
    count_min[0] = 1;
    count_max[0] = 1;
    for (int i = 1; i <= N; i++) {
      if (f_max[i - 1] == f_min[i - 1]) {
        ll from_1 = f_max[i - 1] + a[i];
        ll from_2 = abs(f_max[i - 1] + a[i]);
        ll mx = max(from_1, from_2);
        if (from_1 == mx) {
          f_max[i] = from_1;
          count_max[i] += count_max[i - 1];
        }
        if (from_2 == mx) {
          f_max[i] = from_2;
          count_max[i] += count_max[i - 1];
        }
        ll mn = min(from_1, from_2);
        if (from_1 == mn) {
          f_min[i] = from_1;
          count_min[i] += count_min[i - 1];
        }
        if (from_2 == mn) {
          f_min[i] = from_2;
          count_min[i] += count_min[i - 1];
        }
      } else {
        ll from_min_1 = f_min[i - 1] + a[i];
        ll from_min_2 = abs(f_min[i - 1] + a[i]);
        ll mx_min = max(from_min_1, from_min_2);
        mint way_min = count_min[i - 1];
        if (from_min_1 == from_min_2) {
          way_min *= 2;
        }
        ll from_max_1 = f_max[i - 1] + a[i];
        ll from_max_2 = abs(f_max[i - 1] + a[i]);
        ll mx_max = max(from_max_1, from_max_2);
        mint way_max = count_max[i - 1];
        if (from_max_1 == from_max_2) {
          way_max *= 2;
        }
        if (mx_min == mx_max) {
          f_max[i] = mx_max;
          count_max[i] = way_min + way_max;
        } else if (mx_min > mx_max) {
          f_max[i] = mx_min;
          count_max[i] = way_min;
        } else {
          f_max[i] = mx_max;
          count_max[i] = way_max;
        }

        ll mn_min = min(from_min_1, from_min_2);
        ll mn_max = min(from_max_1, from_max_2);

        if (mn_min == mn_max) {
          f_min[i] = mx_min;
          count_max[i] = way_min + way_max;
        } else if (mn_min < mn_max) {
          f_min[i] = mn_min;
          count_min[i] = way_min;
        } else {
          f_min[i] = mn_max;
          count_min[i] = way_max;
        }
      }
    }
    cout << count_max[N] << '\n';
  }
}
