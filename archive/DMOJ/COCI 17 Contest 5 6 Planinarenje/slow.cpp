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
  int N, M;
  cin >> N >> M;
  vector<set<int>> a(2 * N + 1);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    v += N;
    a[u].insert(v), a[v].insert(u);
  }
  vector<vector<int>> f(2 * N, vector<int>(1 << (2 * N), -1));
  auto sol = yc([&](auto sol, int i, int state) -> int {
    if (f[i][state] != -1) {
      return f[i][state];
    }
    int res = i < N;
    for (int j = 0; j < 2 * N; j++) {
      if (((state >> j) & 1) && a[i].find(j) != a[i].end()) {
        int tmp = sol(j, state ^ (1 << i));
        if (i < N && tmp == 0) {
          res = 0;
        }
        if (i >= N && tmp == 1) {
          res = 1;
        }
      }
    }
    return f[i][state] = res;
  });
  for (int i = 0; i < N; i++) {
    cout << (sol(i, (1 << (2 * N)) - 1) ? "Mirko" : "Slavko") << '\n';
  }
}
