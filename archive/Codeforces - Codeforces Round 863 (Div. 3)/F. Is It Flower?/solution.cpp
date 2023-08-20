/**
 *  author: cunbidun
 *  created: Sunday, 2023-07-23 14:42:09 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

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
    int N, M;
    cin >> N >> M;
    vector<vector<int>> a(N);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    vector<int> visited(N);
    vector<int> s2, s4;
    int total_visited = 0;
    auto dfs = yc([&](auto _dfs, int u) -> void {
      if (a[u].size() == 2) {
        s2.push_back(u);
      }
      if (a[u].size() == 4) {
        s4.push_back(u);
      }
      total_visited += 1;
      visited[u] = 1;
      for (int v : a[u]) {
        if (!visited[v]) {
          _dfs(v);
        }
      }
    });
    auto check = [&](int k) -> bool {
      // debug() << imie(s2);
      // debug() << imie(s4);

      vector<int> visited_inner(N);
      set<int> visited_other;
      int visited_current = 0;
      auto dfs_inner = yc([&](auto _dfs, int u, int cont) -> void {
        visited_inner[u] = 1;
        visited_current += 1;
        for (int v : a[u]) {
          if (!visited_inner[v]) {
            if ((int)a[v].size() == cont) {
              _dfs(v, cont);
            } else {
              visited_other.insert(v);
            }
          }
        }
      });
      for (int v : s2) {
        if (!visited_inner[v]) {
          dfs_inner(v, 2);
          if (visited_other.size() != 1 || visited_current != k - 1) {
            // debug() << imie(visited_other);
            return false;
          }
        }
        visited_other.clear();
        visited_current = 0;
      }
      dfs_inner(s4.front(), 4);
      for (int i : s4) {
        if (!visited_inner[i]) {
          return false;
        }
      }
      return true;
    };
    bool f = 0;
    for (int i = 0; i < N; i++) {
      if (!visited[i]) {
        dfs(i);
        int k = s4.size();
        if (total_visited == N && total_visited == (int)(s2.size() + s4.size()) && k >= 3 &&
            total_visited == 1LL * k * k) {
          if (check(k)) {
            f = 1;
            break;
          }
          total_visited = 0;
          s2.clear();
          s4.clear();
        }
      }
    }
    cout << (f ? "YES" : "NO") << '\n';
  }
};
