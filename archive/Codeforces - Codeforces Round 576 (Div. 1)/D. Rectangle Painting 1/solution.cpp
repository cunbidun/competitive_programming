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
template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args> Vec(int n = 0, Args... args) : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T> struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<vector<char>> a(N + 1, vector<char>(N + 1));
  Vec<4, int> f(N + 1, N + 1, N + 1, N + 1, -1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      cin >> a[i][j];
      int v = 0;
      if (a[i][j] == '#') {
        v = 1;
      }
      f[i][j][i][j] = v;
    }
  }
  auto solve = yc([&](auto _solve, int x1, int y1, int x2, int y2) -> int {
    if (f[x1][y1][x2][y2] != -1) {
      return f[x1][y1][x2][y2];
    }
    f[x1][y1][x2][y2] = max(x2 - x1 + 1, y2 - y1 + 1);
    for (int x = x1; x < x2; x++) {
      f[x1][y1][x2][y2] = min(f[x1][y1][x2][y2], _solve(x1, y1, x, y2) + _solve(x + 1, y1, x2, y2));
    }
    for (int y = y1; y < y2; y++) {
      f[x1][y1][x2][y2] = min(f[x1][y1][x2][y2], _solve(x1, y1, x2, y) + _solve(x1, y + 1, x2, y2));
    }
    return f[x1][y1][x2][y2];
  });
  cout << solve(1, 1, N, N) << '\n';
}
