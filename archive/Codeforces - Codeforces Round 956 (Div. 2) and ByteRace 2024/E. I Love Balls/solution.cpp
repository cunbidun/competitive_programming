#include <bits/stdc++.h>

using namespace std;

template <typename T> T mod_inv(T a, T m) {
  assert(__gcd(a, m) == 1);
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

template <typename T> struct nCk {
  int N;
  vector<T> f, invf;
  nCk(int _n) : N(_n) {
    f.assign(N + 1, 0), invf.assign(N + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
      f[i] = f[i - 1] * i;
    }
    invf[N] = f[N].inv();
    for (int i = N - 1; i >= 0; i--) {
      invf[i] = invf[i + 1] * (i + 1);
    }
  }
  T get(int n, int k) {
    assert(0 <= n && n <= N && 0 <= k && k <= N);
    return (n < k) ? 0 : f[n] * invf[k] * invf[n - k];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using mint = mint<int(1e9 + 7)>;
  auto C = nCk<mint>(int(5e5 + 5));
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    mint sum = 0;
    mint sum_first = 0;
    mint sum_last = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      sum += a[i];
      if (i < K) {
        sum_first += a[i];
      } else {
        sum_last += a[i];
      }
    }
    int x = (N - K + 1) / 2;
    int y = N - K - x;
    if (x == 0) {
      cout << sum << ' ' << 0 << '\n';
      continue;
    }
    mint from_last = sum_last * x * C.f[N - K - 1];

    if (x > y) {
      y++;
    } else {
      x++;
    }
    mint total_way = 0;
    mint total_sum = 0;

    for (int k = 0; k <= K; k++) {
      mint from_x = C.get(k + x - 1, x - 1);
      mint from_y = C.get(K - k + y - 1, y - 1);
      mint num_ways = from_x * from_y * C.f[K];
      total_way += num_ways * C.f[N - K];

      mint contribution = from_x * from_y * k * C.f[K - 1];
      total_sum += contribution * sum_first * C.f[N - K];
      total_sum += from_last * num_ways;
    }
    cout << total_sum / total_way << ' ' << sum - total_sum / total_way << '\n';
  }
}