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
    vector<array<int, 3>> edge;
    for (int i = 1; i <= M; i++) {
      int u, v;
      string s;
      cin >> u >> v >> s;
      int val = 0;
      if (s[0] == 'i') {
        val = 1;
      }
      edge.push_back({u, v, val});
    }
    int ans = -1;
    for (int mask = 0; mask < (1 << N); mask++) {
      int f = 0;
      for (auto [u, v, s] : edge) {
        int uu = (mask >> (u - 1)) & 1;
        int vv = (mask >> (v - 1)) & 1;
        if (uu == 1) {
          f |= (vv != 1 - s);
        } else {
          f |= (vv != s);
        }
      }
      if (!f) {
        ans = max(ans, __builtin_popcount(mask));
      }
    }
    cout << ans << '\n';
  }
}
