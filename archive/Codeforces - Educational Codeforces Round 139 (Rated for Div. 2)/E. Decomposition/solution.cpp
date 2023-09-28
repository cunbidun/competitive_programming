/**
 *  author: cunbidun
 *  created: Friday, 2023-09-15 19:36:05 CDT
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  tensor<int, 4> f({N + 1, 4, 4, 4});
  long long ans = 0;
  int cnt0 = 0;
  for (int i = 1; i <= N; i++) {
    if (a[i] == 0) {
      for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 3; k++) {
          for (int l = 0; l <= 3; l++) {
            f[{i, j, k, l}] += f[{i - 1, j, k, l}];
          }
        }
      }
      cnt0++;
      continue;
    }
    f[{i, a[i], 0, 0}] = 1 + cnt0;
    cnt0 = 0;

    if (a[i] == 1) {
      for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 3; k++) {
          for (int l = 0; l <= 3; l++) {
            if (j != 2) {
              f[{i, 1, k, l}] += f[{i - 1, j, k, l}];
            } else if (k != 2) {
              f[{i, j, 1, l}] += f[{i - 1, j, k, l}];
            } else {
              f[{i, j, k, 1}] += f[{i - 1, j, k, l}];
            }
          }
        }
      }
    }

    if (a[i] == 2) {
      for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 3; k++) {
          for (int l = 0; l <= 3; l++) {
            if (j != 1) {
              f[{i, 2, k, l}] += f[{i - 1, j, k, l}];
            } else if (k != 1) {
              f[{i, j, 2, l}] += f[{i - 1, j, k, l}];
            } else {
              f[{i, j, k, 2}] += f[{i - 1, j, k, l}];
            }
          }
        }
      }
    }

    if (a[i] == 3) {
      for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 3; k++) {
          for (int l = 0; l <= 3; l++) {
            f[{i, 3, k, l}] += f[{i - 1, j, k, l}];
          }
        }
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (a[i] == 0) {
      ans += 1LL * i * (N - i + 1);
    }
    for (int j = 1; j <= 3; j++) {
      for (int k = 0; k <= 3; k++) {
        for (int l = 0; l <= 3; l++) {
          int cnt = 1;
          if (k != 0) {
            cnt++;
          }
          if (l != 0) {
            cnt++;
          }
          ans += f[{i, j, k, l}] * cnt;
        }
      }
    }
  }
  cout << ans << '\n';
}
