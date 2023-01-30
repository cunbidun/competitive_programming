/**
 *  author: cunbidun
 *  created: Wednesday, 2022-12-28 23:21:02 CST
 **/
#include <array>
#include <assert.h>
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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
  vector<int> dis(N);
  bool odd_cycle = false;
  int odd = 0, even = 0;
  yc([&](auto _dfs, int u, int d) -> void {
    dis[u] = d;
    visited[u] = 1;
    if (d % 2 == 0) {
      even += 1;
    } else {
      odd += 1;
    }
    for (int v : a[u]) {
      if (visited[v]) {
        if ((d + 1) % 2 != dis[v] % 2) {
          odd_cycle = true;
        }
      } else {
        _dfs(v, d + 1);
      }
    }
  })(0, 0);
  if (odd_cycle) {
    cout << 1LL * N * (N - 1) / 2 - M << '\n';
  } else {
    cout << 1LL * odd * even - M << '\n';
  }
}
