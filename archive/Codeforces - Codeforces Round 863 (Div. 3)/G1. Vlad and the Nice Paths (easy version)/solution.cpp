/**
 *  author: cunbidun
 *  created: Sunday, 2023-07-23 12:05:37 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T, int NDIMS> struct tensor_view {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  T *data;

  tensor_view(std::array<int, NDIMS> shape_, std::array<int, NDIMS> strides_, T *data_)
      : shape(shape_), strides(strides_), data(data_) {}

public:
  tensor_view() : shape{0}, strides{0}, data(nullptr) {}

protected:
  int flatten_index(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      res += idx[i] * strides[i];
    }
    return res;
  }
  int flatten_index_checked(std::array<int, NDIMS> idx) const {
    int res = 0;
    for (int i = 0; i < NDIMS; i++) {
      assert(0 <= idx[i] && idx[i] < shape[i]);
      res += idx[i] * strides[i];
    }
    return res;
  }

public:
  T &operator[](std::array<int, NDIMS> idx) const { return data[flatten_index(idx)]; }
  T &at(std::array<int, NDIMS> idx) const { return data[flatten_index_checked(idx)]; }

  template <int D = NDIMS> typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](int idx) const {
    std::array<int, NDIMS - 1> nshape;
    std::copy(shape.begin() + 1, shape.end(), nshape.begin());
    std::array<int, NDIMS - 1> nstrides;
    std::copy(strides.begin() + 1, strides.end(), nstrides.begin());
    T *ndata = data + (strides[0] * idx);
    return tensor_view<T, NDIMS - 1>(nshape, nstrides, ndata);
  }
  template <int D = NDIMS> typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) const {
    assert(0 <= idx && idx < shape[0]);
    return operator[](idx);
  }

  template <int D = NDIMS> typename std::enable_if<(0 == D), T &>::type operator*() const { return *data; }

  template <typename U, int D> friend struct tensor_view;
  template <typename U, int D> friend struct tensor;
};

template <typename T, int NDIMS> struct tensor {
  static_assert(NDIMS >= 0, "NDIMS must be nonnegative");

protected:
  std::array<int, NDIMS> shape;
  std::array<int, NDIMS> strides;
  int len;
  T *data;

public:
  tensor() : shape{0}, strides{0}, len(0), data(nullptr) {}

  explicit tensor(std::array<int, NDIMS> shape_, T t = T()) {
    shape = shape_;
    len = 1;
    for (int i = NDIMS - 1; i >= 0; i--) {
      strides[i] = len;
      len *= shape[i];
    }
    data = new T[len];
    std::fill(data, data + len, t);
  }

  tensor(const tensor &o) : shape(o.shape), strides(o.strides), len(o.len), data(new T[len]) {
    for (int i = 0; i < len; i++) {
      data[i] = o.data[i];
    }
  }

  tensor &operator=(tensor &&o) noexcept {
    using std::swap;
    swap(shape, o.shape);
    swap(strides, o.strides);
    swap(len, o.len);
    swap(data, o.data);
    return *this;
  }
  tensor(tensor &&o) : tensor() { *this = std::move(o); }
  tensor &operator=(const tensor &o) { return *this = tensor(o); }
  ~tensor() { delete[] data; }

  using view_t = tensor_view<T, NDIMS>;
  view_t view() { return tensor_view<T, NDIMS>(shape, strides, data); }
  operator view_t() { return view(); }

  T &operator[](std::array<int, NDIMS> idx) { return view()[idx]; }
  T &at(std::array<int, NDIMS> idx) { return view().at(idx); }

  template <int D = NDIMS> typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type operator[](int idx) {
    return view()[idx];
  }
  template <int D = NDIMS> typename std::enable_if<(0 < D), tensor_view<T, NDIMS - 1>>::type at(int idx) {
    return view().at(idx);
  }

  template <int D = NDIMS> typename std::enable_if<(0 == D), T &>::type operator*() { return *view(); }
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
  int T;
  cin >> T;
  using mint = mint<(int)1e9 + 7>;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    if (K == 1) {
      cout << 1 << '\n';
      continue;
    }
    tensor<mint, 2> f({N + 1, N + 1});
    tensor<bool, 2> visited({N + 1, N + 1});

    f[{0, 0}] = 1;
    visited[{0, 0}] = 1;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= i; j++) {
        if (j % K == 1) {
          for (int ip = 0; ip < i; ip++) {
            f[{i, j}] += f[{ip, j - 1}];
            visited[{i, j}] |= visited[{ip, j - 1}];
          }
        } else {
          for (int ip = 0; ip < i; ip++) {
            if (a[i] == a[ip]) {
              f[{i, j}] += f[{ip, j - 1}];
              visited[{i, j}] |= visited[{ip, j - 1}];
            }
          }
        }
      }
    }

    int longest = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= i; j++) {
        if (visited[{i, j}] && j % K == 0) {
          longest = max(longest, j);
        }
      }
    }
    mint ans = 0;
    // cout << f[{5, 4}] << '\n';
    // cout << f[{6, 4}] << '\n';
    // cout << f[{7, 4}] << '\n';
    // cout << longest << '\n';
    for (int i = 0; i <= N; i++) {
      ans += f[{i, longest}];
    }

    cout << ans << '\n';
  }
}
