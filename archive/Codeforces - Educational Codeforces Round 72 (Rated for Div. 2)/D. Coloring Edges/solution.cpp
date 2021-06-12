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
  vector<vector<array<int, 2>>> a(N);
  for (int i = 0; i < M; i++) {
    int U, V;
    cin >> U >> V;
    U--, V--;
    a[U].push_back({V, i});
  }
  vector<int> color(N);
  vector<int> ans(M);
  auto dfs = yc([&](auto dfs, int u) -> void {
    color[u] = 1;
    for (auto [v, i] : a[u]) {
      if (color[v] == 2) {
        ans[i] = 1;
      } else if (color[v] == 0) {
        ans[i] = 1;
        dfs(v);
      } else {
        ans[i] = 2;
      }
    }
    color[u] = 2;
  });
  for (int i = 0; i < N; i++) {
    if (color[i] == 0) {
      dfs(i);
    }
  }
  cout << *max_element(ans.begin(), ans.end()) << '\n';
  for (int i : ans) {
    cout << i << ' ';
  }
  cout << '\n';
}
