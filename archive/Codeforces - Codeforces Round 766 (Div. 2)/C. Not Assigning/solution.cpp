#include <bits/stdc++.h>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
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
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<array<int, 2>>> a(N);
    int f = 0;
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u].push_back({v, i});
      a[v].push_back({u, i});
      f |= a[u].size() > 2;
      f |= a[v].size() > 2;
    }
    if (f) {
      cout << -1 << '\n';
      continue;
    }
    vector<int> ans(N - 1);
    int pos = -1;
    for (int i = 0; i < N; i++) {
      if (a[i].size() == 1) {
        pos = i;
        break;
      }
    }
    int cur = 0;
    yc([&](auto dfs, int u, int l) -> void {
      for (auto [v, i] : a[u]) {
        if (v != l) {
          if (cur == 0) {
            ans[i] = 2;
          } else {
            ans[i] = 3;
          }
          cur = 1 - cur;
          dfs(v, u);
        }
      }
    })(pos, pos);
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
