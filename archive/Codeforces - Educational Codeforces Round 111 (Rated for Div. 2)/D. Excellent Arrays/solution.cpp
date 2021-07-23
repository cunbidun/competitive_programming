#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;
struct mint {
  int v;
  explicit operator int() const { return v; } // explicit -> don't silently convert to int
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) {
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<mint> f(2e5 + 1);
  f[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    f[i] = f[i - 1] * i;
  }
  auto C = [&](int n, int k) -> mint {
    return f[n] / (f[k] * f[n - k]);
  };
  int T;
  cin >> T;
  while (T--) {
    mint ans = 0;
    int N, L, R;
    cin >> N >> L >> R;
    int full = min(R - N, abs(L - 1));
    ans = C(N, N / 2) * full;
    if (N % 2 == 1) {
      ans += C(N, N / 2 + 1) * full;
    }
    int mn = min(R - 1, abs(L - N));
    for (int i = mn; i > full; i--) {
      int cntp = min(N, R - i);
      int cntn = min(N, -i - (L - N) + 1);
      if (cntp >= N / 2 && cntn >= N / 2 && cntp + cntn >= N) {
        int left = N - cntn;
        int right = N - cntp;
        int l = N - left - right;
        if (N / 2 >= left) {
          ans += C(l, N / 2 - left);
        }
        if (N % 2 == 1 && cntp > N / 2) {
          ans += C(l, N / 2 + 1 - left);
        }
      }
    }
    cout << ans.v << '\n';
  }
}
