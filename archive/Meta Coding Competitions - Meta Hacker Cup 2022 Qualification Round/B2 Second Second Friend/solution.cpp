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
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, C;
    cin >> R >> C;
    vector<vector<char>> a(R + 2, vector<char>(C + 2, '#'));
    vector<vector<char>> o(R + 2, vector<char>(C + 2, '#'));
    int cnt = 0;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        cin >> a[i][j];
        if (a[i][j] == '^') {
          cnt++;
        }
        o[i][j] = a[i][j];
      }
    }
    if (cnt == 0) {
      cout << "Possible\n";
      for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
          cout << a[i][j];
        }
        cout << '\n';
      }
      continue;
    }
    if (R == 1 || C == 1) {
      cout << "Impossible\n";
      continue;
    }
    auto count_rock = [&](int i, int j) -> int {
      return (a[i + 1][j] == '#') + (a[i][j + 1] == '#') + (a[i - 1][j] == '#') + (a[i][j - 1] == '#');
    };
    int f = 0;
    auto dfs = yc([&](auto _dfs, int i, int j) -> void {
      if (a[i][j] == '#' || count_rock(i, j) < 3) {
        return;
      }
      if (a[i][j] == '^') {
        f = 1;
      }
      a[i][j] = '#';
      _dfs(i + 1, j);
      _dfs(i - 1, j);
      _dfs(i, j - 1);
      _dfs(i, j + 1);
    });
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        dfs(i, j);
      }
    }
    if (f == 1) {
      cout << "Impossible\n";
      continue;
    }
    cout << "Possible\n";
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        if (o[i][j] == '#' || o[i][j] == '^') {
          cout << o[i][j];
        } else {
          if (a[i][j] != '#') {
            cout << '^';
          } else {
            cout << o[i][j];
          }
        }
      }
      cout << '\n';
    }
  }
}
