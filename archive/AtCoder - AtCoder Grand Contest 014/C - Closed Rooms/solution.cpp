/**
 *  author: cunbidun
 *  created: Monday, 2023-03-27 21:27:38 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
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
  int H, W, K;
  cin >> H >> W >> K;
  vector<vector<int>> A(H, vector<int>(W, 0));
  vector<vector<int>> visited(H, vector<int>(W, 1e9));
  int x, y;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      char c;
      cin >> c;
      if (c == '#') {
        A[i][j] = 1;
      }
      if (c == 'S') {
        x = i, y = j;
      }
    }
  }

  int dx[] = {0, 0, -1, 1};
  int dy[] = {-1, 1, 0, 0};
  queue<array<int, 2>> q;
  q.push({x, y});
  visited[x][y] = 0;
  while (!q.empty()) {
    auto [i, j] = q.front();
    q.pop();

    for (int k = 0; k < 4; k++) {
      int ni = i + dx[k];
      int nj = j + dy[k];
      if (0 <= ni && 0 <= nj && ni < H && nj < W && visited[ni][nj] == 1e9 && A[ni][nj] != 1) {
        visited[ni][nj] = min(visited[ni][nj], visited[i][j] + 1);
        q.push({ni, nj});
      }
    }
  };
  int ans = 1e9;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (visited[i][j] <= K) {
        // cout << i << ' ' << j << '\n';
        int dis = min({i, j, H - 1 - i, W - 1 - j});
        ans = min(ans, (dis + K - 1) / K + 1);
      }
    }
  }
  cout << ans << '\n';
}
