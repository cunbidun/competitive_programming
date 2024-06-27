#include <bits/stdc++.h>

using namespace std;

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1);
    int root = -1;
    for (int i = 1; i <= N - 1; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back(v);
      a[v].push_back(u);
      if (a[u].size() > 1) {
        root = u;
      }
      if (a[v].size() > 1) {
        root = v;
      }
    }
    if (N == 2) {
      cout << N << '\n';
      continue;
    }
    // f[u][0][1] = max mis size of the tree rooted at u, u not selected and there is a missing leave
    // f[u][1][1] = max mis size of the tree rooted at u, u is selected and there is a missing leave
    // f[u][0][0] = max mis size of the tree rooted at u, u not selected and there is NO missing leave
    // f[u][1][0] = max mis size of the tree rooted at u, u is selected and there is NO missing leave
    vector<vector<vector<int>>> f(N + 1, vector<vector<int>>(2, vector<int>(2, 0)));
    yc([&](auto dfs, int u, int l) -> void {
      if (a[u].size() == 1) {
        f[u][0][0] = 0;
        f[u][1][0] = 1;
        f[u][0][1] = 0;
        f[u][1][1] = 0;
        return;
      }
      f[u][1][0] = 1;
      int diff_selected = 1e9;
      int diff_not_selected = 1e9;
      for (int v : a[u]) {
        if (v != l) {
          dfs(v, u);
          // u is selected
          f[u][1][0] += f[v][0][0];
          diff_selected = min(diff_selected, f[v][0][0] - f[v][0][1]);

          // u is not selected
          f[u][0][0] += max(f[v][1][0], f[v][0][0]);
          diff_not_selected = min(diff_not_selected, max(f[v][1][0], f[v][0][0]) - max(f[v][0][1], f[v][1][1]));
        }
      }
      f[u][0][1] = f[u][0][0] - diff_not_selected;
      f[u][1][1] = f[u][1][0] - diff_selected;
    })(root, root);
    cout << max(f[root][1][1], f[root][0][1]) + 1 << '\n';
  }
}

// Step by step solution:
// 1. The first node can always be a leave -> we only consider selecting leave as the first node
// 2. Given the first root is selected, no 2 adj nodes can both be leaves -> max is the size of MIS
// 3. Then the answer would be 1 + max of the size of MIS of all tree that missing 1 leave
