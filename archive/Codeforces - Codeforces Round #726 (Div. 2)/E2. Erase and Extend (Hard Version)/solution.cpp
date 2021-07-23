#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
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
    v = (1LL * v * m.v) % MOD;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  string s;
  cin >> s;
  vector<mint> h(N);
  h[0] = s[0] - 'a' + 1;
  mint prime = mint(1903);
  for (int i = 1; i < N; i++) {
    h[i] = h[i - 1] * prime + mint(s[i] - 'a' + 1);
  }
  vector<mint> p(N + 1);
  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = p[i - 1] * prime;
  }
  auto check_equal = [&](int i, int j) -> bool {
    if (i == 0) {
      return 1;
    }
    mint left = h[j - 1];
    mint right = h[i + j - 1] - h[i - 1] * p[j];
    return left == right;
  };
  auto check = [&](int i) -> bool {
    if (check_equal(i, N - i)) {
      return 1;
    }
    int l = 1, r = N - i;
    while (l < r) {
      int m = (l + r) / 2;
      if (check_equal(i, m)) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return s[l - 1] < s[i + l - 1];
  };
  for (int i = 1; i < (int)s.size(); i++) {
    if (check(i)) {
      s = s.substr(0, i);
      break;
    }
  }
  while ((int)s.length() < K) {
    s = s + s;
  }
  cout << s.substr(0, K) << '\n';
}
