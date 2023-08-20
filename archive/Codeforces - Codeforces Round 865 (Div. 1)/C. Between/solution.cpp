/**
 *  author: cunbidun
 *  created: Wednesday, 2023-06-07 22:24:32 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
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
  auto solve = []() -> void {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N + 1);
    vector<int> count(N + 1);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      a[v].push_back(u);
    }
    count[1] = 1;

    queue<int> q;
    q.push(1);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int v : a[u]) {
        if (count[v] == 0) {
          count[v] = count[u] + 1;
          q.push(v);
        }
      }
    }
    for (int i = 1; i <= N; i++) {
      if (count[i] == 0) {
        cout << "INFINITE" << '\n';
        return;
      }
    }
    // debug() << imie(count);
    vector<array<int, 2>> location;
    for (int i = 1; i <= N; i++) {
      int lowest = 0;
      if (count[i] % 2 == 0) {
        lowest = i - N - (count[i] / 2 - 1) * 2 * N;
      } else {
        lowest = i - (count[i] / 2) * 2 * N;
      }
      // cout << i << ' ' << lowest << '\n';
      for (int j = 0; j < count[i]; j++) {
        location.push_back({lowest + 2 * N * j, i});
      }
    }
    sort(location.begin(), location.end());

    cout << "FINITE" << '\n';
    cout << location.size() << '\n';
    for (auto [p, x] : location) {
      cout << x << ' ';
    }
    cout << '\n';
  };
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
