#include <bits/stdc++.h>

using namespace std;

template <class c> struct rge {
  c b, e;
};
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N * 2 + 1);
    for (int i = 1; i <= 2 * N; i++) {
      cin >> a[i];
    }
    set<int> current_set;
    vector<int> checked(N * 2 + 1);
    vector<vector<int>> g(N + 1);
    vector<int> has_parent(N + 1);
    for (int i = 1; i <= 2 * N; i++) {
      if (checked[a[i]]) {
        current_set.erase(checked[a[i]]);
      } else {
        if (!current_set.empty()) {
          int largest = *current_set.rbegin();
          int value = a[largest];
          g[value].push_back(a[i]);
          has_parent[a[i]] = value;
          // cout << value << " -> " << a[i] << '\n';
        }
        checked[a[i]] = i;
        current_set.insert(i);
      }
    }
    current_set.clear();
    checked.assign(N + 1, 0);
    for (int i = 2 * N; i >= 1; i--) {
      if (checked[a[i]]) {
        current_set.erase(checked[a[i]]);
      } else {
        if (!current_set.empty()) {
          int largest = *current_set.begin();
          int value = a[largest];
          g[value].push_back(a[i]);
          has_parent[a[i]] = value;
          // cout << value << " -> " << a[i] << '\n';
        }
        checked[a[i]] = i;
        current_set.insert(i);
      }
    }
    for (int i = 1; i <= N; i++) {
      g[i].push_back(i);
    }
    vector<int> visited(N + 1);
    int num_visted = 0;
    auto dfs = yc([&](auto _dfs, int u) -> void {
      visited[u] = 1;
      num_visted++;
      for (int v : g[u]) {
        if (!visited[v]) {
          _dfs(v);
        }
      }
    });

    int cnt_mn = 0;
    for (int i = 1; i <= N; i++) {
      if (!has_parent[i]) {
        cnt_mn++;
        dfs(i);
      }
    }
    int ans = 1;
    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        num_visted = 0;
        cnt_mn++;
        dfs(i);
        ans = (ans * num_visted) % 998244353;
      }
    }
    cout << cnt_mn << ' ' << ans << '\n';
  }
}
