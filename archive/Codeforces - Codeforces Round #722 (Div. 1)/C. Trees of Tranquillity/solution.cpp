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
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1), b(N + 1);
    for (int i = 2; i <= N; i++) {
      int p;
      cin >> p;
      a[p].push_back(i);
    }
    for (int i = 2; i <= N; i++) {
      int p;
      cin >> p;
      b[p].push_back(i);
    }
    int t = 0;
    vector<int> i(N + 1), o(N + 1);
    yc([&](auto dfs, int u) -> void {
      i[u] = ++t;
      for (int v : b[u]) {
        dfs(v);
      }
      o[u] = ++t;
    })(1);
    // debug() << imie(i) << imie(o);
    set<array<int, 3>> s;
    vector<vector<array<int, 2>>> op(N + 1);
    int ans = 0;
    yc([&](auto dfs, int u) -> void {
      auto it = s.upper_bound({i[u], o[u]});
      if (it != s.begin()) {
        it--;
        if ((*it)[1] > o[u]) {
          op[u].push_back({0, (*it)[2]});
          s.erase(it);
        }
      }
      it = s.upper_bound({i[u], o[u]});
      if (it == s.end()) {
        s.insert({i[u], o[u], u});
        op[u].push_back({1, u});
      } else {
        if ((*it)[0] > o[u]) {
          s.insert({i[u], o[u], u});
          op[u].push_back({1, u});
        }
      }
      // debug() << imie(u) << imie(s);
      ans = max(ans, (int)s.size());
      for (int v : a[u]) {
        dfs(v);
        for (auto e : op[v]) {
          if (e[0] == 1) {
            s.erase({i[e[1]], o[e[1]], e[1]});
          } else {
            s.insert({i[e[1]], o[e[1]], e[1]});
          }
        }
      }
    })(1);
    cout << ans << '\n';
  }
}
