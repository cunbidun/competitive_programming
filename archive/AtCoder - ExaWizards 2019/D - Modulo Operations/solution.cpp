/**
 *  author: cunbidun
 *  created: Saturday, 2023-03-11 12:40:05 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using mint = mint<1000000007>;
  int N, X;
  cin >> N >> X;
  vector<int> S(N);
  // lte[i] = list of number in the array that <= x
  vector<vector<int>> lte(X + 1);
  // gt[i] = number of elements in the array that > x
  vector<int> gt(X + 1);

  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  for (int i = 0; i <= X; i++) {
    for (int j = 0; j < N; j++) {
      if (i < S[j]) {
        gt[i]++;
      } else {
        lte[i].push_back(S[j]);
      }
    }
  }

  // f[i][j] = number of way to reach number i after selecting j number from the array
  vector<vector<mint>> f(X + 1, vector<mint>(N + 1, 0));
  // Base case there are 1 way to reach x without selecting any number from the array
  f[X][0] = 1;

  for (int i = 1; i <= N; i++) {
    for (int x = X; x >= 0; x--) {
      // This check avoid adding unreachable state.
      // When a < b, b % a <= b/2. There for the total number of reachable state is
      // X * N * log(X)
      if (f[x][i - 1] != 0) {
        for (int j : lte[x]) {
          f[x % j][i] += f[x][i - 1];
        }
        f[x][i] += f[x][i - 1] * (gt[x] - (i - 1));
      }
    }
  }
  mint ans = 0;
  for (int i = 1; i <= X; i++) {
    ans += i * f[i][N];
  }
  cout << ans << '\n';
}
