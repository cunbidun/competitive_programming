#include <array>
#include <functional>
#include <iostream>
#include <vector>

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

using namespace std;

template <class c> struct rge { c b, e; };
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
    int N, K;
    cin >> N >> K;
    vector<vector<int>> a(N + 1);
    vector<int> s(N + 1);
    for (int i = 2; i <= N; i++) {
      int p;
      cin >> p;
      a[p].push_back(i);
    }

    for (int i = 1; i <= N; i++) {
      cin >> s[i];
    }

    vector<array<int, 2>> mx(N + 1);
    yc([&](auto _dfs, int u) -> array<int, 2> {
      int cur_mx = 0;
      int pos = -1;
      for (int v : a[u]) {
        auto [v_mx, v_pos] = _dfs(v);
        if (v_mx > cur_mx) {
          cur_mx = v_mx;
          pos = v_pos;
        }
      }
      return mx[u] = {cur_mx + s[u], ((pos != -1) ? pos : u)};
    })(1);

    debug() << imie(mx);
  }
}
