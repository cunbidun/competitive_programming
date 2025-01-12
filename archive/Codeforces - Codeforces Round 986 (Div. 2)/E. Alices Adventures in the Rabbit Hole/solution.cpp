#include <bits/stdc++.h>

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
  int T;
  cin >> T;
  using mint = mint<998244353>;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1);
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    vector<int> p(N + 1), d(N + 1);
    yc([&](auto dfs, int u, int l) -> void {
      for (int v : a[u]) {
        if (v != l) {
          d[v] = d[u] + 1;
          p[v] = u;
          dfs(v, u);
        }
      }
    })(1, 1);
    vector<int> leaf;
    for (int i = 1; i <= N; i++) {
      if (a[i].size() == 1) {
        leaf.push_back(i);
      }
    }

    vector<mint> ans(N + 1);
    ans[1] = 1;
    sort(leaf.begin(), leaf.end(), [&](int a, int b) { return d[a] < d[b]; });
    for (int l : leaf) {
      if (l == 1) {
        continue;
      }

      ans[l] = 0;
      int c = p[l];
      mint top = 0;
      int count = 0;
      while (true) {
        if (ans[c] != 0) {
          top = ans[c];
          break;
        }
        c = p[c];
        count += 1;
      }
      count += 1;
      c = p[l];
      int current = 1;
      while (true) {
        if (ans[c] != 0) {
          break;
        }
        ans[c] = top * mint(current) / mint(count);
        c = p[c];
        current += 1;
      }
    }
    for (int i = 1; i <= N; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
