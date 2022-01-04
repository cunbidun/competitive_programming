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
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--;
      v--;
      a[u].push_back(v), a[v].push_back(u);
    }
    int b = 0, w = 0;
    vector<int> bn, wn;
    yc([&](auto dfs, int u, int l, int c) -> void {
      if (c == 1) {
        b++;
        bn.push_back(u);
      } else {
        w++;
        wn.push_back(u);
      }
      for (int v : a[u]) {
        if (v != l) {
          dfs(v, u, 1 - c);
        }
      }
    })(0, 0, 0);
    if (b < w) {
      swap(b, w);
      swap(bn, wn);
    }
    set<int> index;
    for (int i = 0; i < 25; i++) {
      if ((w >> i) & 1) {
        index.insert(i);
      }
    }
    vector<int> lw, lb;
    for (int i = 1; i <= N; i++) {
      int cnt = 0;
      int tmp = i;
      while (tmp) {
        tmp /= 2;
        cnt++;
      }
      cnt--;
      if (index.find(cnt) != index.end()) {
        lw.push_back(i);
      } else {
        lb.push_back(i);
      }
    }
    vector<int> ans(N);
    for (int i = 0; i < w; i++) {
      ans[wn[i]] = lw[i];
    }
    for (int i = 0; i < b; i++) {
      ans[bn[i]] = lb[i];
    }
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
