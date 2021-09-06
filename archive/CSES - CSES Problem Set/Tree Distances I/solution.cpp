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
  int N;
  cin >> N;
  vector<vector<int>> a(N + 1);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int mx = 0;
  int p = -1;
  vector<int> mx_d(N + 1);
  auto dfs = yc([&](auto _dfs, int u, int l, int lvl) -> void {
    mx_d[u] = max(mx_d[u], lvl);
    if (lvl > mx) {
      p = u;
      mx = lvl;
    }
    for (int v : a[u]) {
      if (v != l) {
        _dfs(v, u, lvl + 1);
      }
    }
  });
  dfs(1, 1, 0);
  int p1 = p;
  dfs(p1, p1, 0);
  int p2 = p;
  dfs(p2, p2, 0);
  for (int i = 1; i <= N; i++) {
    cout << mx_d[i] << ' ';
  }
  cout << '\n';
}
