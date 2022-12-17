/**
 *  author: cunbidun
 *  created: Wednesday, 2022-12-07 17:37:55 CST
 *  tags: best-problem
 **/
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
  vector<vector<int>> h(N, vector<int>(N));
  vector<vector<int>> occ(N, vector<int>(N));
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      h[i][j] = min({i, j, N - 1 - i, N - 1 - j});
      occ[i][j] = 1;
    }
  }
  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  auto dfs = yc([&](auto _dfs, int x, int y) -> void {
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (nx < 0 || ny < 0 || N <= nx || N <= ny) {
        continue;
      }
      if (h[nx][ny] > h[x][y] + occ[x][y]) {
        h[nx][ny] = h[x][y] + occ[x][y];
        _dfs(nx, ny);
      }
    }
  });
  int ans = 0;
  for (int i = 0; i < N * N; i++) {
    int p;
    cin >> p;
    p--;
    int x = p / N;
    int y = p % N;
    ans += h[x][y];
    occ[x][y] = 0;
    dfs(x, y);
  }
  cout << ans << '\n';
}
