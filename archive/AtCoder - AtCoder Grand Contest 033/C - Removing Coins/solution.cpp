#include <array>
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
  int N;
  cin >> N;
  vector<vector<int>> a(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  vector<int> d(N, 0);
  auto dfs = yc([&](auto _dfs, int u, int l) -> void {
    for (int v : a[u]) {
      if (v != l) {
        d[v] = d[u] + 1;
        _dfs(v, u);
      }
    }
  });
  dfs(0, 0);
  int mx = 0, pos = 0;
  for (int i = 0; i < N; i++) {
    if (mx < d[i]) {
      mx = d[i];
      pos = i;
    }
  }
  d.assign(N, 0);
  dfs(pos, pos);
  auto mxval = *max_element(d.begin(), d.end());
  if ((mxval + 1) % 3 == 2) {
    cout << "Second\n";
  } else {
    cout << "First\n";
  }
}
