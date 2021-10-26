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
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    vector<vector<int>> t(N);
    int s = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      s ^= a[i];
    }
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      t[u].push_back(v), t[v].push_back(u);
    }
    if (s == 0) {
      cout << "YES\n";
      continue;
    }
    if (K - 1 == 1) {
      cout << "NO\n";
      continue;
    }
    int nu = -1, nl;
    int found = 0;
    auto cal = yc([&](auto dfs, int u, int l, int r) -> int {
      int tot_xor = a[u];
      for (int v : t[u]) {
        if (v != l) {
          tot_xor ^= dfs(v, u, r);
        }
      }
      if (u != r && found == 0 && tot_xor == s) {
        found = 1;
        nu = l;
        nl = u;
      }
      return tot_xor;
    });
    cal(0, 0, 0);
    if (!found) {
      cout << "NO\n";
      continue;
    }
    found = 0;
    cal(nu, nl, nl);
    if (found) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
