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
  int N, M, P;
  cin >> N >> M >> P;
  vector<vector<int>> a(N);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v), a[v].push_back(u);
  }
  vector<vector<int>> g(2 * N, vector<int>(31));
  vector<array<int, 2>> visited(2 * N);
  auto dfs = yc([&](auto _dfs, int u, int s) -> void {
    visited[u][s] = 1;
    int v = a[u][0];
    if (a[u].size() > 1) {
      v = a[u][1 - s];
    }
    int v_s = (a[v][0] != u);
    g[2 * u + s][0] = 2 * v + v_s;
    if (!visited[v][v_s]) {
      _dfs(v, v_s);
    }
  });
  for (int i = 0; i < N; i++) {
    if (!visited[i][1]) {
      dfs(i, 1);
    }
  }
  for (int j = 1; j < 31; j++) {
    for (int i = 0; i < 2 * N; i++) {
      g[i][j] = g[g[i][j - 1]][j - 1];
    }
  }
  auto jump = [&](int cur, int k) -> int {
    for (int i = 30; i >= 0; i--) {
      if ((k >> i) & 1) {
        cur = g[cur][i];
      }
    }
    return cur;
  };
  int Q;
  cin >> Q;
  while (Q--) {
    int K;
    cin >> K;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      if (jump(i * 2 + 1, K) / 2 == P) {
        ans++;
      }
    }
    cout << ans << ' ';
  }
  cout << '\n';
}
