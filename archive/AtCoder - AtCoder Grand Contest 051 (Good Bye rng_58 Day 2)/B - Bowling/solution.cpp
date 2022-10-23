#include <array>
#include <functional>
#include <iostream>
#include <set>
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

  vector<array<int, 2>> points;

  auto build = yc([&](auto _build, int level, int x, int y) -> void {
    if (level == 0) {
      points.push_back({x, y});
      return;
    }
    int cur = 1;
    for (int i = 0; i < level; i++) {
      cur *= 3;
    }
    _build(level - 1, x, y);
    _build(level - 1, x, y + cur);
    _build(level - 1, x + cur, y + cur);
  });
  build(6, 0, 0);

  cout << points.size() << '\n';
  for (auto [x, y] : points) {
    cout << x << ' ' << y << '\n';
  }
}
