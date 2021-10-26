#include <bits/stdc++.h>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
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
  friend std::ostream &operator<<(std::ostream &out, const mint &n) {
    return out << int(n);
  }
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

template <int MXBIT> struct trie_bit {
  int id;
  vector<array<int, 2>> trie;
  trie_bit(int _sz) : id(1), trie(vector<array<int, 2>>(_sz)) {}

  void add(long long n) {
    int cur = 1;
    int f = 0;
    for (int i = MXBIT - 1; i >= 0; i--) {
      int b = (n >> i) & 1;
      f |= (!f && b == 1);
      if (f) {
        if (trie[cur][b] == 0) {
          trie[cur][b] = ++id;
        }
        cur = trie[cur][b];
      }
    }
  }

  bool check(long long n) {
    int cur = 1;
    int f = 0;
    for (int i = MXBIT - 1; i >= 0; i--) {
      int b = (n >> i) & 1;
      f |= (!f && b == 1);
      if (f) {
        if (trie[cur][b] == 0) {
          return false;
        }
        cur = trie[cur][b];
      }
    }
    return true;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  trie_bit<60> t(2000 * 70);
  using mint = mint<1000000007>;
  int K, N;
  cin >> K >> N;
  map<long long, int> mp;

  auto numbit = [&](long long n) -> int {
    int res = 0;
    while (n) {
      res++;
      n >>= 1;
    }
    return res;
  };

  for (int i = 0; i < N; i++) {
    long long x;
    string s;
    cin >> x >> s;
    t.add(x);
    if (s[0] == 'w') {
      mp[x] = 1;
    }
    if (s[0] == 'y') {
      mp[x] = 6;
    }
    if (s[0] == 'b') {
      mp[x] = 2;
    }
    if (s[0] == 'g') {
      mp[x] = 5;
    }
    if (s[0] == 'r') {
      mp[x] = 3;
    }
    if (s[0] == 'o') {
      mp[x] = 4;
    }
  }
  vector<vector<mint>> f(K + 1, vector<mint>(7, 0));
  for (int i = 1; i <= 6; i++) {
    f[1][i] = 1;
  }
  for (int i = 2; i <= K; i++) {
    for (int c = 1; c <= 6; c++) {
      for (int j = 1; j <= 6; j++) {
        for (int k = 1; k <= 6; k++) {
          if (c != j && c != k && c + j != 7 && c + k != 7) {
            f[i][c] += f[i - 1][j] * f[i - 1][k];
          }
        }
      }
    }
  }

  auto res = yc([&](auto sol, long long n) -> vector<mint> {
    auto it = mp.find(n);
    if (numbit(n) == K) {
      if (it != mp.end()) {
        vector<mint> r(7);
        r[it->second] = 1;
        return r;
      }
      return vector<mint>(7, 1);
    }
    if (it == mp.end()) {
      if (!t.check(n)) {
        return f[K - numbit(n) + 1];
      }

      auto left = sol(n * 2);
      auto right = sol(n * 2 + 1);
      vector<mint> r(7);

      for (int c = 1; c <= 6; c++) {
        for (int j = 1; j <= 6; j++) {
          for (int k = 1; k <= 6; k++) {
            if (c != j && c != k && c + j != 7 && c + k != 7) {
              r[c] += left[j] * right[k];
            }
          }
        }
      }
      return r;
    }

    auto left = sol(n * 2);
    auto right = sol(n * 2 + 1);
    int c = it->second;
    vector<mint> r(7);
    for (int j = 1; j <= 6; j++) {
      for (int k = 1; k <= 6; k++) {
        if (c != j && c != k && c + j != 7 && c + k != 7) {
          r[c] += left[j] * right[k];
        }
      }
    }
    return r;
  })(1);

  mint ans = 0;
  for (int i = 1; i <= 6; i++) {
    ans += res[i];
  }
  cout << ans << '\n';
}
