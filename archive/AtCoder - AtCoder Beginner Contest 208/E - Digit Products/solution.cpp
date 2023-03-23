/**
 *  author: cunbidun
 *  created: Saturday, 2023-02-25 19:38:16 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

namespace std {
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
} // namespace std

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

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N, K;
  cin >> N >> K;
  string sn = to_string(N);
  map<long long, int> mp;
  auto get_index = [&](long long p) -> int {
    if (mp.find(p) == mp.end()) {
      mp[p] = mp.size();
    }
    return mp[p];
  };
  reverse(sn.begin(), sn.end());
  auto cal_digit = [&](int d) -> int { return sn[d] - '0'; };
  tensor<long long, 4> f({20, 10, 50000, 2}, -1);
  auto cal = yc([&](auto solve, int d, int mx, int c, long long p) -> long long {
    // cout << d << ' ' << mx << ' ' << c << ' ' << p << '\n';
    int idx = get_index(p);
    if (f[{d, c, idx, mx}] != -1) {
      return f[{d, c, idx, mx}];
    }
    if (d == 0) {
      if (p <= K) {
        return f[{d, c, idx, mx}] = 1;
      } else {
        return f[{d, c, idx, mx}] = 0;
      }
    }
    long long res = 0;
    for (long long i = 0; i <= 9; i++) {
      if (mx) {
        if (i <= cal_digit(d - 1)) {
          res += solve(d - 1, i == cal_digit(d - 1), i, p * i);
        }
      } else {
        res += solve(d - 1, mx, i, p * i);
      }
    }
    return f[{d, c, idx, mx}] = res;
  });
  long long ans = 0;
  for (int d = sn.size() - 1; d >= 0; d--) {
    for (long long i = 1; i <= 9; i++) {
      if (d == (int)sn.size() - 1) {
        if (i <= sn.back() - '0') {
          ans += cal(d, i == sn.back() - '0', i, i);
          // cout << d << ' ' << i << ' ' << cal(d, i == sn.back() - '0', i, i) << '\n';
        }
      } else {
        ans += cal(d, 0, i, i);
        // cout << d << ' ' << i << ' ' << cal(d, 0, i, i) << '\n';
      }
    }
  }
  cout << ans << '\n';
}
