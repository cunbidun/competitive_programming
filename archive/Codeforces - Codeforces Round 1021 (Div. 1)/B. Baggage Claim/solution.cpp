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
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M, K;
    cin >> N >> M >> K;
    map<array<int, 2>, int> mp;
    map<array<int, 2>, set<array<int, 2>>> neighbors;
    vector<vector<int>> graph(2 * (K + 1) + 1);
    int last_x = -1, last_y = -1;
    int f = 0;
    set<int> all_nodes;
    for (int i = 0; i < K + 1; i++) {
      int x, y;
      cin >> x >> y;
      if (f) {
        continue;
      }
      if (i != 0) {
        if (abs(x - last_x) + abs(y - last_y) != 2) {
          f = 1;
          continue;
        }
        vector<array<int, 2>> cans;
        if (x == last_x) {
          cans.push_back({x, (y + last_y) / 2});
          cans.push_back({x, (y + last_y) / 2});
        } else if (y == last_y) {
          cans.push_back({(x + last_x) / 2, y});
          cans.push_back({(x + last_x) / 2, y});
        } else {
          cans.push_back({x, last_y});
          cans.push_back({last_x, y});
        }
        for (auto [can_x, can_y] : cans) {
          if (mp.find({can_x, can_y}) == mp.end()) {
            mp[{can_x, can_y}] = mp.size() + 1;
          }
        }
        int u = mp[{cans[0][0], cans[0][1]}];
        int v = mp[{cans[1][0], cans[1][1]}];
        all_nodes.insert(u);
        all_nodes.insert(v);
        graph[u].push_back(v);
        // cout << cans[0][0] << ' ' << cans[0][1] << '\n';
        // cout << cans[1][0] << ' ' << cans[1][1] << '\n';
        // cout << u << " -> " << v << '\n';
        graph[v].push_back(u);
      }
      last_x = x;
      last_y = y;
    }
    if (f) {
      cout << 0 << '\n';
      continue;
    }
    mint<1000000007> ans = 1;
    vector<int> visited(2 * (K + 1) + 1);
    for (int u : all_nodes) {
      if (visited[u]) {
        continue;
      }
      int count = 0;
      int edge_count = 0;
      int has_self_loop = 0;
      yc([&](auto dfs, int r) -> void {
        count += 1;
        visited[r] = 1;
        for (int v : graph[r]) {
          if (v == r) {
            has_self_loop = 1;
          }
          edge_count += 1;
          if (!visited[v]) {
            dfs(v);
          }
        }
      })(u);
      edge_count /= 2;

      if (edge_count > count) {
        ans *= 0;
      }
      if (edge_count < count) {
        ans *= count;
      }
      if (edge_count == count) {
        if (!has_self_loop) {
          ans *= 2;
        }
      }
    }
    cout << ans << '\n';
  }
}
