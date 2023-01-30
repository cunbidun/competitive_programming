/**
 *  author: cunbidun
 *  created: Sunday, 2023-01-29 13:28:27 CST
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
  if (M % 2 == 1) {
    cout << "-1\n";
    return 0;
  }

  vector<vector<array<int, 2>>> g(N + 1);
  vector<array<int, 2>> edge;
  vector<int> flipped(M);
  vector<int> visited(N + 1);

  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    g[A].push_back({B, (int)edge.size()});
    g[B].push_back({A, (int)edge.size()});
    edge.push_back({A, B});
  }

  yc([&](auto _dfs, int u, int edge_id) -> int {
    visited[u] = 1;
    int res = 0;
    int cur_out = 0;
    for (auto [v, id] : g[u]) {
      if (!visited[v]) {
        res += _dfs(v, id);
      }
      cur_out += (u == edge[id][0]);
    }
    res += cur_out % 2;
    if (res % 2 && edge_id != -1) {
      // cout << u << ' ' << cur_out << ' ' << res << ' ' << edge_id << '\n';
      flipped[edge_id] = 1;
    }
    return res;
  })(1, -1);

  for (int i = 0; i < M; i++) {
    auto [a, b] = edge[i];
    if (!flipped[i]) {
      cout << a << ' ' << b << '\n';
    } else {
      cout << b << ' ' << a << '\n';
    }
  }
}
