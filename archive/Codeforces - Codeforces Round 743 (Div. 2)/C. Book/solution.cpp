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

template <class c> struct rge { c b, e; };
template <class c> rge<c> range(c i, c j) { return rge<c>{i, j}; }
template <class c> auto dud(c *x) -> decltype(cerr << *x, 0);
template <class c> char dud(...);
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
  template <class c, class b> debug &operator<<(pair<b, c> d) {
    return *this << "(" << d.first << ", " << d.second << ")";
  }
  template <class c> debug &operator<<(rge<c> d) {
    *this << "[";
    for (auto it = d.b; it != d.e; ++it) {
      *this << ", " + 2 * (it == d.b) << *it;
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
    vector<vector<int>> a(N);
    vector<vector<int>> p(N);
    for (int i = 0; i < N; i++) {
      int k;
      cin >> k;
      for (int j = 0; j < k; j++) {
        int par;
        cin >> par;
        par--;
        a[par].push_back(i);
        p[i].push_back(par);
      }
    }
    vector<int> l;
    vector<int> visited(N);
    int f = 0;
    auto dfs = yc([&](auto _dfs, int u) -> void {
      visited[u] = 1;
      for (int v : a[u]) {
        if (visited[v] == 1) {
          f = 1;
        }
        if (!visited[v]) {
          _dfs(v);
        }
      }
      visited[u] = 2;
      l.push_back(u);
    });
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        dfs(i);
      }
    }
    if (f) {
      cout << -1 << '\n';
      continue;
    }
    reverse(l.begin(), l.end());
    vector<int> d(N);
    int ans = 0;
    for (int i : l) {
      for (int par : p[i]) {
        if (par < i) {
          d[i] = max(d[i], d[par]);
        } else {
          d[i] = max(d[i], d[par] + 1);
        }
      }
      if (d[i] == 0) {
        d[i] = 1;
      }
      ans = max(ans, d[i]);
    }
    // debug() << imie(d);
    cout << ans << '\n';
  }
}
