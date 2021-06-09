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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(N);
  for (int i = 0; i < M; i++) {
    int U, V;
    cin >> U >> V;
    U--, V--;
    a[U].push_back(V);
  }
  vector<int> visited(N);
  int cnt = 0;
  int ans = 0;
  auto dfs = yc([&](auto dfs, int u) -> void {
    visited[u] = 1;
    cnt++;
    for (int v : a[u]) {
      if (!visited[v]) {
        dfs(v);
      }
    }
  });
  for (int i = 0; i < N; i++) {
    visited.assign(N, 0);
    cnt = 0;
    dfs(i);
    ans += cnt;
  }
  cout << ans << '\n';
}
