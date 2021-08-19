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
    a[u].push_back(v), a[v].push_back(u);
  }
  yc([&](auto dfs, int u, int l) -> void {
    cout << u << ' ';
    vector<int> list;
    for (int v : a[u]) {
      if (v != l) {
        list.push_back(v);
      }
    }
    sort(list.begin(), list.end());
    for (int v : list) {
      dfs(v, u);
      cout << u << '\n';
    }
  })(1, 1);
}
