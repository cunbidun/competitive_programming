#include <bits/stdc++.h>

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

int MOD = 998244353;
struct mint {
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
  friend std::ostream &operator<<(std::ostream &out, const mint &n) {
    return out << int(n);
  }
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
  struct mint_nck {
    int N;
    vector<mint> f, invf;
    mint_nck(int _n) : N(_n) {
      f.assign(N + 1, 0), invf.assign(N + 1, 0);
      f[0] = 1;
      for (int i = 1; i <= N; i++) {
        f[i] = f[i - 1] * i;
      }
      invf[N] = f[N].pow(MOD - 2);
      for (int i = N - 1; i >= 0; i--) {
        invf[i] = invf[i + 1] * (i + 1);
      }
    }
    mint get(int n, int k) {
      assert(0 <= n && n <= N && 0 <= k && k <= N);
      return (n < k) ? 0 : f[n] * invf[k] * invf[n - k];
    }
  };
  mint_nck c(200005);
  int T;
  cin >> T;
  vector<mint> f(200005);
  f[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    f[i] = f[i - 1] * i;
  }
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    if (a[N - 1] == a[N - 2]) {
      cout << f[N] << '\n';
    } else if (a[N - 1] - 1 != a[N - 2]) {
      cout << 0 << '\n';
    } else {
      int cnt = 0;
      for (int i = 0; i < N; i++) {
        if (a[i] == a[N - 2]) {
          cnt++;
        }
      }
      mint w = c.get(N, cnt + 1) * f[cnt] * f[N - cnt - 1];
      cout << f[N] - w << '\n';
    }
  }
}
