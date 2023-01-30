/**
 *  author: cunbidun
 *  created: Wednesday, 2023-01-25 22:47:04 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
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
  int N;
  cin >> N;
  vector<vector<array<int, 2>>> tree(N);
  for (int i = 0; i < N - 1; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    tree[a].push_back({b, i});
    tree[b].push_back({a, i});
  }
  vector<vector<vector<int>>> pair_to_edge_list(N, vector<vector<int>>(N, vector<int>()));
  auto dfs = yc([&](auto _dfs, int r, int u, int l) -> void {
    for (auto [v, id] : tree[u]) {
      if (v != l) {
        pair_to_edge_list[r][v] = pair_to_edge_list[r][u];
        pair_to_edge_list[r][v].push_back(id);
        _dfs(r, v, u);
      }
    }
  });
  for (int i = 0; i < N; i++) {
    dfs(i, i, i);
  }

  int M;
  cin >> M;
  vector<array<int, 2>> edge_list;
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    edge_list.push_back({u, v});
  }
  auto cal = [&](int mask) -> long long {
    vector<int> marked(N);
    for (int i = 0; i < M; i++) {
      if ((mask >> i) & 1) {
        auto [u, v] = edge_list[i];
        for (int id : pair_to_edge_list[u][v]) {
          marked[id] = 1;
        }
      }
    }
    int sum = 0;
    for (int i : marked) {
      sum += i;
    }
    return 1LL << (N - 1 - sum);
  };
  long long total_fail = 0;
  for (int mask = 1; mask < (1 << M); mask++) {
    int bit_count = __builtin_popcount(mask);
    if (bit_count % 2 == 0) {
      total_fail -= cal(mask);
    } else {
      total_fail += cal(mask);
    }
  }
  cout << (1LL << (N - 1)) - total_fail << '\n';
}
