#include <bits/stdc++.h>

using namespace std;

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

template <class c> struct rge {
  c b, e;
};
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
struct debug {
#ifdef LOCAL
  ~debug() { cout << endl; }
  template <class c> typename enable_if<sizeof dud<c>(0) != 1, debug &>::type operator<<(c i) {
    cout << boolalpha << i;
    return *this;
  }
  template <class c> typename enable_if<sizeof dud<c>(0) == 1, debug &>::type operator<<(c i) {
    return *this << range(begin(i), end(i));
  }
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ((it == d.b) ? "" : ", ") << *it;
    }
    return *this << "]";
  }
#else
  template <class c> debug &operator<<(const c &) { return *this; }
#endif
};
#define imie(...) "[" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<vector<int>> t(N + 1);
    for (int i = 1; i < N; i++) {
      int u, v;
      cin >> u >> v;
      t[u].push_back(v);
      t[v].push_back(u);
    }
    using ll = long long;
    ll INF = 1e18;
    vector<array<ll, 4>> f(N + 1, {-INF, -INF, -INF, -INF});

    ll ans = 0;
    yc([&](auto dfs, int u, int l) -> void {
      vector<pair<ll, int>> prev;
      for (int v : t[u]) {
        if (v != l) {
          dfs(v, u);
          ll mxv3 = f[v][0];
          if (f[v][1] != -INF) {
            mxv3 = max(mxv3, f[v][1] - a[v]);
          }
          if (f[v][2] != -INF) {
            mxv3 = max(mxv3, f[v][2]);
          }
          if (f[v][3] != -INF) {
            mxv3 = max(mxv3, f[v][3]);
          }
          prev.push_back({mxv3, v});
        }
      }
      sort(prev.begin(), prev.end(), [&](auto F, auto S) { return F.first > S.first; });

      f[u][0] = a[u];
      if (prev.size() >= 1) {
        f[u][1] = a[u] + prev[0].first;
      }
      if (prev.size() >= 2) {
        f[u][2] = a[u] + prev[0].first + prev[1].first;
      }
      if (prev.size() >= 3) {
        f[u][3] = a[u] + prev[0].first + prev[1].first + prev[2].first;
        for (int i = 3; i < (int)prev.size(); i++) {
          f[u][3] += max(prev[i].first, 0LL);
        }
      }
      ans = max({ans, f[u][0], f[u][2] - a[u], f[u][1], f[u][3]}); // f[u][2] is not real
    })(1, 1);

    cout << ans << '\n';
  }
}
