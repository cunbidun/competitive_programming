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
  int N, K;
  cin >> N >> K;
  vector<string> a(N * K);
  for (int i = 0; i < N; i++) {
    int p;
    cin >> p;
    for (int j = 0; j < K; j++) {
      cin >> a[p * K + j];
    }
  }
  vector<int> ch(26);
  for (string s : a) {
    for (int i = 0; i < (int)s.size(); i++) {
      ch[s[i] - 'a'] = 1;
    }
  }
  vector<set<int>> g(26, set<int>());
  for (int i = 1; i < N * K; i++) {
    int f = 0;
    for (int j = 0; j < (int)min(a[i - 1].size(), a[i].size()); j++) {
      if (a[i - 1][j] != a[i][j]) {
        g[a[i - 1][j] - 'a'].insert(a[i][j] - 'a');
        f = 1;
        break;
      }
    }
    if (!f && a[i].size() < a[i - 1].size()) {
      cout << "IMPOSSIBLE\n";
      return 0;
    }
  }
  vector<int> visited(26);
  int ok = 1;
  vector<int> l;

  auto dfs = yc([&](auto dfs, int u) -> void {
    visited[u] = 1;
    for (int v : g[u]) {
      if (visited[v] == 1) {
        ok = 0;
      }
      if (!visited[v]) {
        dfs(v);
      }
    }
    visited[u] = 2;
    l.push_back(u);
  });

  for (int i = 0; i < 26; i++) {
    if (ch[i] && !visited[i]) {
      dfs(i);
    }
  }
  if (!ok) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }
  reverse(l.begin(), l.end());
  // debug() << l << '\n';
  for (int i : l) {
    cout << (char)(i + 'a');
  }
  cout << '\n';
}
