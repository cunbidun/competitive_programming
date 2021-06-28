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
  int MOD = 1e9 + 7;
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<int>> a(N + 1);
  vector<long long> x(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> x[i];
  }
  for (int i = 1; i < N; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v), a[v].push_back(u);
  }

  vector<int> lvl(N + 1);
  vector<vector<long long>> gcd(N + 1, vector<long long>(20));
  vector<vector<long long>> p(N + 1, vector<long long>(20));
  lvl[1] = 1;
  yc([&](auto dfs, int u, int l = 1) -> void {
    for (int v : a[u]) {
      if (v != l) {
        gcd[v][0] = __gcd(x[u], x[v]);
        p[v][0] = u;
        lvl[v] = lvl[u] + 1;
        dfs(v, u);
      }
    }
  })(1);
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= N; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
    }
  }
  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= N; i++) {
      gcd[i][j] = __gcd(gcd[i][j - 1], gcd[p[i][j - 1]][j - 1]);
    }
  }
  int ans = 0;

  yc([&](auto dfs, int u, int l = 1) -> void {
    long long cur = u;
    long long cur_g = x[u];
    int res = 0;
    while (cur != 0) {
      int most = cur;
      for (int j = 19; j >= 0; j--) {
        if (p[most][j] != 0 && __gcd(cur_g, gcd[most][j]) == cur_g) {
          most = p[most][j];
        }
      }
      int add = ((lvl[cur] - lvl[most] + 1) * cur_g % MOD) % MOD;
      res = (res + add) % MOD;
      cur = p[most][0];
      cur_g = __gcd(cur_g, x[cur]);
    }
    ans = (ans + res) % MOD;
    for (int v : a[u]) {
      if (v != l) {
        dfs(v, u);
      }
    }
  })(1);
  cout << ans << '\n';
}
