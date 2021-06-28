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
    vector<int> ia(N + 1), oa(N + 1);
    yc([&](auto dfs, int u) -> void {
      ia[u] = ++t;
      for (int v : a[u]) {
        dfs(v);
      }
      oa[u] = ++t;
    })(1);
    vector<int> ib(N + 1), ob(N + 1);
    t = 0;
    yc([&](auto dfs, int u) -> void {
      ib[u] = ++t;
      for (int v : b[u]) {
        dfs(v);
      }
      ob[u] = ++t;
    })(1);
    // debug() << imie(ib) << imie(ob);
    int ans = 0;
    for (int mask = 0; mask < (1 << N); mask++) {
      vector<int> v;
      for (int i = 0; i < N; i++) {
        if ((mask >> i) & 1) {
          v.push_back(i + 1);
        }
      }
      int ok = 1;
      for (int i : v) {
        for (int j : v) {
          if (i != j) {
            if (!((ia[i] < ia[j] && oa[j] < oa[i]) || (ia[j] < ia[i] && oa[i] < oa[j]))) {
              ok = 0;
            }
            if (!((ob[i] < ib[j]) || (ob[j] < ib[i]))) {
              ok = 0;
            }
          }
        }
      }
      if (ok) {
        ans = max(ans, (int)v.size());
      }
    }
    cout << ans << '\n';
  }
}

