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
  int Q;
  cin >> Q;
  while (Q--) {
    int N, K;
    cin >> N >> K;
    vector<vector<array<int, 2>>> a(N + 1, vector<array<int, 2>>());
    for (int i = 1; i < N; i++) {
      int U, V, W;
      cin >> U >> V >> W;
      a[U].push_back({V, W}), a[V].push_back({U, W});
    }
    vector<array<long long, 2>> f(N + 1);
    yc([&](auto dfs, int u, int l) -> void {
      vector<array<long long, 3>> list;
      for (auto [v, w] : a[u]) {
        if (v != l) {
          dfs(v, u);
          list.push_back({f[v][1] + w - f[v][0], f[v][0], v});
        }
      }
      long long res0 = 0, res1 = 0;
      sort(list.begin(), list.end(), [](auto A, auto B) { return A[0] > B[0]; });
      int cnt0 = 0, cnt1 = 0;
      for (auto e : list) {
        int inc = (e[0] > 0);
        if (cnt0 + inc <= K) {
          res0 += max(e[1], e[1] + e[0]);
          cnt0 += inc;
        } else {
          res0 += e[1];
        }
        if (cnt1 + inc < K) {
          res1 += max(e[1], e[1] + e[0]);
          cnt1 += inc;
        } else {
          res1 += e[1];
        }
      }
      f[u][0] = res0;
      f[u][1] = res1;
    })(1, 1);
    cout << f[1][0] << '\n';
  }
}
