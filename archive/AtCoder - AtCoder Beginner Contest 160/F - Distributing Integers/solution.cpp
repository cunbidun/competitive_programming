/**
 *  author: cunbidun
 *  created: Saturday, 2023-02-18 19:45:35 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  using mint = mint<1000000007>;
  vector<vector<int>> a(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<mint> f(N);
  vector<mint> fac(N + 1);
  vector<int> size(N);
  fac[0] = 1;
  for (int i = 1; i <= N; i++) {
    fac[i] = fac[i - 1] * i;
  }

  yc([&](auto dfs, int u, int l) -> int {
    size[u] = 1;
    for (int v : a[u]) {
      if (v != l) {
        size[u] += dfs(v, u);
      }
    }
    return size[u];
  })(0, 0);

  yc([&](auto dfs, int u, int l) -> mint {
    mint res = fac[size[u] - 1];
    for (int v : a[u]) {
      if (v != l) {
        res *= dfs(v, u);
        res /= fac[size[v]];
      }
    }
    return f[u] = res;
  })(0, 0);

  vector<mint> ans(N);
  ans[0] = f[0];
  yc([&](auto dfs, int u, int l, mint from_p) -> void {
    ans[u] = from_p;

    mint choice = fac[N - 1];
    choice /= fac[N - size[u]];

    for (int v : a[u]) {
      if (v != l) {
        ans[u] *= f[v];
        choice /= fac[size[v]];
      }
    }
    for (int v : a[u]) {
      if (v != l) {
        mint from_p_v = choice / fac[N - 1] * fac[N - size[v] - 1] * fac[size[v]] * (ans[u] / f[v]);
        dfs(v, u, from_p_v);
      }
    }
    ans[u] *= choice;
  })(0, 0, 1);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << '\n';
  }
}
