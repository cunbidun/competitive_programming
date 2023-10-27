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
  int N, K;
  cin >> N >> K;
  using mint = mint<998244353>;
  vector<vector<mint>> g(N + 1, vector<mint>(K + 1));
  vector<vector<mint>> sum_g(N + 1, vector<mint>(K + 1));
  vector<mint> p(N + 1);
  mint k_fac = 1;
  for (int i = 2; i <= K; i++) {
    k_fac *= i;
  }
  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = K * p[i - 1];
  }
  sum_g[0][K - 1] = 1;
  for (int i = 1; i < K; i++) {
    g[1][i] = 1;
    sum_g[1][i] = g[1][i] + sum_g[1][i - 1];
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j < K; j++) {
      g[i][j] = sum_g[i - 1][K - 1] - sum_g[i - 1][j - 1];
      g[i][j] += g[i - 1][j - 1] * (K - (j - 1));
      sum_g[i][j] = g[i][j] + sum_g[i][j - 1];
    }
  }
  vector<mint> f(N + 1);
  for (int i = K; i <= N; i++) {
    for (int j = 0; j <= i - K; j++) {
      f[i] += (f[j] + p[j]) * k_fac * sum_g[i - j - K][K - 1];
    }
  }
  cout << f[N] << '\n';
}
