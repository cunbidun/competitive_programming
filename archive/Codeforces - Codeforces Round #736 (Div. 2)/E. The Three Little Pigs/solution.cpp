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

struct mint_nck {
  int N;
  vector<mint> f, invf;
  mint_nck(int _n) : N(_n) {
    f.assign(N + 1, 0), invf.assign(N + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
      f[i] = f[i - 1] * i;
    }
    invf[N] = pow(f[N], MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
      invf[i] = invf[i + 1] * (i + 1);
    }
  }
  mint get(int n, int k) {
    assert(0 <= n && n <= N && 0 <= k && k <= N);
    return (n < k) ? 0 : f[n] * invf[k] * invf[n - k];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  mint_nck C(3 * N + 1);
  vector<vector<mint>> dp(3 * N + 2, vector<mint>(3));
  vector<mint> p(3 * N + 2);
  for (int i = 0; i <= (3 * N + 1) / 2; i++) {
    p[i] = C.get(3 * N + 1, i);
    p[3 * N + 1 - i] = p[i];
  }
  mint inv3 = inv(mint(3));
  dp[0][0] = N + 1; // come at min 0
  dp[0][1] = N;
  dp[0][2] = N;
  for (int i = 0; i <= 3 * N - 1; i++) {
    dp[i + 1][0] = (p[i + 2] + 2 * p[i + 1] - 2 * dp[i][0] - dp[i][1]) * inv3;
    dp[i + 1][1] = dp[i][0] + dp[i + 1][0] - p[i + 1];
    dp[i + 1][2] = dp[i][1] + dp[i + 1][1];
  }
  while (Q--) {
    int x;
    cin >> x;
    cout << dp[x][0].v << '\n';
  }
}
