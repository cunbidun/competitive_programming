#include <bits/stdc++.h>

using namespace std;

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
  int N;
  cin >> N;
  vector<vector<int>> a(N + 1);
  vector<array<int, 2>> edge;
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  auto ask = [](set<int> &v) {
    cout << "? ";
    cout << v.size() << ' ';
    for (int i : v) {
      cout << i << ' ';
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
  };
  set<int> s;
  for (int i = 1; i <= N; i++) {
    s.insert(i);
  }
  int mx = ask(s);
  yc([&](auto dfs, int u, int l) -> void {
    if (l != -1) {
      edge.push_back({u, l});
    }
    for (int v : a[u]) {
      if (v != l) {
        dfs(v, u);
      }
    }
    if (l != -1) {
      edge.push_back({u, l});
    }
  })(1, -1);
  int l = 0, r = edge.size() - 1;
  while (l < r) {
    int m = (l + r) / 2;
    set<int> tmp;
    for (int i = l; i <= m; i++) {
      tmp.insert(edge[i][1]);
      tmp.insert(edge[i][0]);
    }
    int val = ask(tmp);
    if (val != mx) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  cout << "! " << edge[l][0] << ' ' << edge[l][1] << endl;
}
/*
9
1 2
1 3
2 7
2 5
5 9
5 8
3 4
3 6
  */
