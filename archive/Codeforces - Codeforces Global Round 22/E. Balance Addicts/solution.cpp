/**
 *  author: cunbidun
 *  created: Monday, 2023-09-18 23:40:33 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <unordered_map>
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

template <int MOD> struct mint_nck {
  int N;
  vector<mint<MOD>> f, invf;
  mint_nck(int _n) : N(_n) {
    f.assign(N + 1, 0), invf.assign(N + 1, 0);
    f[0] = 1;
    for (int i = 1; i <= N; i++) {
      f[i] = f[i - 1] * i;
    }
    invf[N] = f[N].pow(MOD - 2);
    for (int i = N - 1; i >= 0; i--) {
      invf[i] = invf[i + 1] * (i + 1);
    }
  }
  mint<MOD> get(int n, int k) {
    assert(0 <= n && n <= N && 0 <= k && k <= N);
    return (n < k) ? 0 : f[n] * invf[k] * invf[n - k];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using mint = mint<998244353>;
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    mint_nck<998244353> C(N + 1);
    auto compute_c = [&](int x, int y) -> mint {
      int k = min(x, y);
      mint res = 0;
      for (int i = 0; i <= k; i++) {
        res += C.get(y, i) * C.get(x, i);
      }
      return res;
    };
    auto compute = yc([&](auto f, int l, int r) -> mint {
      // cout << l << ' ' << r << '\n';
      if (a[l] == 0 && a[r] == 0) {
        int p = l, q = r;
        for (int i = l; i < r; i++) {
          if (a[i] != 0) {
            p = i;
            break;
          }
        }
        if (p == l) {
          return mint(2).pow(r - l);
        }
        for (int i = r; i >= l; i--) {
          if (a[i] != 0) {
            q = i;
            break;
          }
        }
        // cout << (p - l) << ' ' << r - q << '\n';
        return compute_c(p - l, r - q) * f(p, q);
      }
      int cur_l = l, cur_r = r;
      long long left = a[cur_l], right = a[cur_r];
      while (left != right) {
        if (left == right) {
          break;
        }
        if (left < right) {
          cur_l++;
          left += a[cur_l];
        } else {
          cur_r--;
          right += a[cur_r];
        }
        if (cur_r == cur_l) {
          return 1;
        }
      }
      if (cur_l == r) {
        return 1;
      }

      int p = cur_l, q = cur_r;
      for (int i = cur_l + 1; i <= cur_r - 1; i++) {
        if (a[i] != 0) {
          p = i;
          break;
        }
      }
      if (p == cur_l) {
        return mint(2).pow(cur_r - cur_l);
      }
      for (int i = cur_r - 1; i >= cur_l + 1; i--) {
        if (a[i] != 0) {
          q = i;
          break;
        }
      }
      return compute_c(p - cur_l, cur_r - q) * f(p, q);
    });
    cout << compute(0, N - 1) << '\n';
  }
}
