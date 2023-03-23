/**
 *  author: cunbidun
 *  created: Thursday, 2023-03-09 21:36:10 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <class T> class Matrix {
public:
  vector<vector<T>> a;
  int r, c;

  Matrix(int r_, int c_, const T &val = T()) : r(r_), c(c_) {
    a.resize(r_);
    for (int i = 0; i < r_; i++) {
      a[i].assign(c_, val);
    }
  }

  Matrix operator+(const Matrix &o) const {
    Matrix res(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        res.a[i][j] = a[i][j] + o.a[i][j];
      }
    }
    return res;
  }

  Matrix operator*(const Matrix &o) const {
    assert(c == o.r);
    Matrix res(r, o.c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < o.c; j++)
        for (int k = 0; k < c; k++) {
          res.a[i][j] += a[i][k] * o.a[k][j];
        }
    }
    return res;
  }

  vector<T> operator*(const vector<T> &v) const {
    assert(this->c == (int)v.size());
    vector<T> res(this->r);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < c; j++) {
        res[i] += a[i][j] * v[j];
      }
    }
    return res;
  }

  Matrix power(int p) const {
    if (p == 0) {
      Matrix res(r, r);
      for (int i = 0; i < r; i++) {
        res.a[i][i] = 1;
      }
      return res;
    }
    if (p == 1) {
      Matrix res(*this);
      return res;
    }
    Matrix tmp = power(p / 2);
    if (p % 2 == 0) {
      return tmp * tmp;
    }
    return *this * tmp * tmp;
  }

  vector<T> &operator[](int i) { return a[i]; }

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
    for (int i = 0; i < matrix.r; i++) {
      for (int j = 0; j < matrix.c; j++) {
        stream << matrix.a[i][j] << " ";
      }
      stream << endl;
    }
    return stream;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using mint = mint<1000000007>;
  int N, M, K;
  cin >> N >> M >> K;
  vector<mint> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  Matrix<mint> base(N, N);

  vector<int> cnt(N);
  for (int i = 0; i < M; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    cnt[x]++;
    cnt[y]++;
    base[x][y] += mint(1) / (2 * M);
    base[y][x] += mint(1) / (2 * M);
    base[x][x] += mint(1) / (2 * M);
    base[y][y] += mint(1) / (2 * M);
  }
  for (int i = 0; i < N; i++) {
    base[i][i] += mint(M - cnt[i]) / M;
  }
  base = base.power(K);
  auto res = base * A;
  for (auto i : res) {
    cout << i << '\n';
  }
}
