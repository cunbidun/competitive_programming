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
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> a(N + 1);
    for (int i = 1; i <= M; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      int val = 0;
      if (s[0] == 'i') {
        val = 1;
      }
      a[u].push_back({v, val});
      a[v].push_back({u, val});
    }
    vector<array<int, 2>> visited(N + 1, {-1, -1});

    auto cal = [&](int r, int im) -> int {
      int f = 0;
      int cnt = 0;
      auto dfs = yc([&](auto _dfs, int u, int val) -> void {
        visited[u][im] = val;
        cnt += val; // 1 for imposter
        for (auto [v, s] : a[u]) {
          if (visited[v][im] == -1) {
            if (val == 1) {
              _dfs(v, 1 - s);
            } else {
              _dfs(v, s);
            }
          } else {
            if (val == 1) {
              f |= (1 - s != visited[v][im]);
            } else {
              f |= (s != visited[v][im]);
            }
          }
        }
      });

      dfs(r, im);
      if (f) {
        return -1;
      }
      return cnt;
    };
    int ans = 0;
    for (int i = 1; i <= N; i++) {
      if (visited[i][0] == -1) {
        int cnt0 = cal(i, 0);
        int cnt1 = cal(i, 1);
        int res = -1;
        res = max({res, cnt0, cnt1});
        if (res == -1) {
          ans = -1;
          break;
        }
        ans += res;
      }
    }
    cout << ans << '\n';
  }
}
