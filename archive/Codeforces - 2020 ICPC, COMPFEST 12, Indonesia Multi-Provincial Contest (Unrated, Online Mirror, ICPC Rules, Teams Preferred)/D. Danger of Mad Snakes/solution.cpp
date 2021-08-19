#include <bits/stdc++.h>

using namespace std;

template <typename T>
T mod_inv(T a, T m) {
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

template <int MOD>
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
  using mint = mint<(int)1e9 + 7>;

  int MX = 2000;
  vector<vector<mint>> f(MX + 1, vector<mint>(MX + 1));
  f[0][0] = 1;
  for (int i = 1; i <= MX; i++) {
    f[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      f[i][j] = f[i - 1][j] + f[i - 1][j - 1];
    }
  }

  int N, M, R;
  cin >> N >> M >> R;
  vector<array<int, 3>> a(N);
  vector<vector<int>> s(MX + 1, vector<int>(MX + 1));
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1] >> a[i][2];
    s[a[i][0]][a[i][1]]++;
  }

  for (int i = 1; i <= MX; i++) {
    for (int j = 1; j <= MX; j++) {
      s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + s[i][j];
    }
  }

  auto get_sum = [&](int x1, int y1, int x2, int y2) -> int {
    if (x1 > x2 || y1 > y2) {
      return 0;
    }
    x1 = max(1, x1);
    y1 = max(1, y1);
    x2 = min(MX, x2);
    y2 = min(MX, y2);
    return s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];
  };
  auto d = [&](int i, int j) -> int {
    return max(abs(a[i][0] - a[j][0]), abs(a[i][1] - a[j][1]));
  };
  mint ans = 0;
  for (int i = 0; i < N; i++) {
    int cnt = 0;
    for (int j = 0; j < N; j++) {
      if (d(i, j) <= R) {
        cnt++;
      }
    }
    mint co = f[N][M] - f[N - cnt][M];
    ans += co * a[i][2] * a[i][2];
  }
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int Y = get_sum(a[i][0] - R, a[i][1] - R, a[i][0] + R, a[i][1] + R);
      int Z = get_sum(a[j][0] - R, a[j][1] - R, a[j][0] + R, a[j][1] + R);
      int X = get_sum(max(a[i][0], a[j][0]) - R, max(a[i][1], a[j][1]) - R,
                      min(a[i][0], a[j][0]) + R, min(a[i][1], a[j][1]) + R);
      Y -= X;
      Z -= X;
      mint co = f[N][M] + f[N - X - Y - Z][M] - f[N - X - Y][M] - f[N - X - Z][M];
      ans += co * 2 * a[i][2] * a[j][2];
    }
  }
  cout << ans << '\n';
}
