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

struct mod_int {
  int MOD;
  mod_int(int _MOD) : MOD(_MOD) {
  }
  int add(int x, int y) {
    return ((x + y) >= MOD ? x + y - MOD : x + y);
  }
  int sub(int x, int y) {
    return ((x - y) < 0 ? x - y + MOD : x - y);
  }
  int mul(int x, int y) {
    return (int)((1LL * x * y) % MOD);
  }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) {
    return pow(x, MOD - 2);
  }
  int div(int x, int y) {
    return mul(x, inv(y));
  }
} o(998244353);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> a(N);
  for (int i = 1; i < N; i++) {
    int p = 0;
    cin >> p;
    p--;
    a[p].push_back(i);
  }
  vector<array<int, 3>> f(N);
  yc([&](auto dfs, int u) -> void {
    int n = a[u].size();
    if (n == 0) {
      f[u][0] = 0;
      f[u][1] = 0;
      f[u][2] = 1;
      return;
    }
    f[u][0] = 1;
    f[u][2] = 1;
    vector<int> list;
    list.push_back(1);
    for (int v : a[u]) {
      dfs(v);
      f[u][0] = o.mul(f[u][0], o.add(f[v][0], f[v][2]));
      list.push_back(o.add(f[v][0], f[v][2]));
    }
    list.push_back(1);
    vector<int> l(n + 1);
    l[0] = 1;
    for (int i = 1; i <= n; i++) {
      l[i] = o.mul(l[i - 1], list[i]);
    }
    int cur = 1;
    for (int i = n; i >= 1; i--) {
      int v = a[u][i - 1];
      int lr = o.mul(l[i - 1], cur);
      int c = o.add(f[v][1], f[v][2]);
      f[u][1] = o.add(f[u][1], o.mul(lr, c));
      cur = o.mul(cur, list[i]);
    }
    for (int v : a[u]) {
      int v0 = o.add(f[v][0], f[v][2]);
      int v1 = o.add(f[v][1], f[v][2]);
      f[u][2] = o.mul(f[u][2], o.add(v0, v1));
    }
    f[u][2] = o.sub(f[u][2], f[u][1]);
    f[u][2] = o.sub(f[u][2], f[u][0]);
  })(0);
  cout << o.add(f[0][0], f[0][2]) << '\n';
}
