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
  cout << fixed << setprecision(10);
  int N;
  cin >> N;
  vector<vector<int>> a(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v), a[v].push_back(u);
  }
  double ans = 0;
  yc([&](auto dfs, int u, int lvl, int l = 0) -> void {
    ans += 1.0 / lvl;
    for (int v : a[u]) {
      if (v != l) {
        dfs(v, lvl + 1 ,u);
      }
    }
  })(0, 1);
  cout << ans << '\n';
}
