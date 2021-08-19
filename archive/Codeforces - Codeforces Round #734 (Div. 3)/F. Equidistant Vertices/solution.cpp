#include <bits/stdc++.h>

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun>
decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

using namespace std;

const int MOD = 1e9 + 7;
struct mint {
  int v;
  explicit operator int() const { return v; }
  mint() { v = 0; }
  mint(long long _v) {
    v = int((-MOD < _v && _v < MOD) ? _v : _v % MOD);
    if (v < 0) { // explicit -> don't silently convert to int
      v += MOD;
    }
  }
  friend mint pow(mint a, long long p) {
    mint ans = 1;
    assert(p >= 0);
    for (; p; p /= 2, a *= a) {
      if (p & 1) {
        ans *= a;
      }
    }
    return ans;
  }
  friend mint inv(const mint &a) {
    assert(a.v != 0);
    return pow(a, MOD - 2);
  }
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
  mint &operator/=(const mint &m) { return (*this) *= inv(m); }
  mint operator-() const { return mint(-v); }
  mint &operator++() { return *this += 1; }
  mint &operator--() { return *this -= 1; }
  friend bool operator==(const mint &a, const mint &b) { return a.v == b.v; }
  friend bool operator!=(const mint &a, const mint &b) { return !(a == b); }
  friend bool operator<(const mint &a, const mint &b) { return a.v < b.v; }
  friend mint operator+(mint a, const mint &b) { return a += b; }
  friend mint operator-(mint a, const mint &b) { return a -= b; }
  friend mint operator*(mint a, const mint &b) { return a *= b; }
  friend mint operator/(mint a, const mint &b) { return a /= b; }
};

template <class c>
struct rge { c b, e; };
template <class c>
rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c>
auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c>
  typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c>
  typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b>
  debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c>
  debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
    }
    return *this << "]";
  }
#else
  template <class c>
  debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<vector<int>> a(N);
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u].push_back(v), a[v].push_back(u);
    }
    if (K == 2) {
      cout << N * (N - 1) / 2 << '\n';
      continue;
    }
    auto cal = [&](int s, int r, vector<int> &vec) {
      vector<int> lvl(N);
      lvl[s] = 1;
      yc([&](auto dfs, int u, int l) -> void {
        for (int v : a[u]) {
          if (v != l) {
            lvl[v] = lvl[u] + 1;
            dfs(v, u);
          }
        }
      })(s, r);
      for (int i = 0; i < N; i++) {
        vec[lvl[i]]++;
      }
    };
    auto solve = [&](vector<int> &arr) -> mint {
      vector<vector<mint>> f(arr.size() + 1, vector<mint>(K + 1));
      for (int i = 0; i <= (int)arr.size(); i++) {
        f[i][0] = 1;
      }
      for (int i = 1; i <= (int)arr.size(); i++) {
        for (int j = 1; j <= K; j++) {
          f[i][j] = f[i - 1][j] + f[i - 1][j - 1] * arr[i - 1];
        }
      }
      return f[arr.size()][K];
    };
    mint ans = 0;
    for (int i = 0; i < N; i++) {
      if ((int)a[i].size() >= K) {
        vector<vector<int>> cnt(N, vector<int>(N + 1, 0));
        for (int j : a[i]) {
          cal(j, i, cnt[j]);
        }
        for (int j = 1; j <= N; j++) {
          vector<int> arr;
          for (int k = 0; k < N; k++) {
            if (cnt[k][j] != 0) {
              arr.push_back(cnt[k][j]);
            }
          }
          if ((int)arr.size() >= K) {
            ans += solve(arr);
          }
        }
      }
    }
    cout << ans.v << '\n';
  }
}
