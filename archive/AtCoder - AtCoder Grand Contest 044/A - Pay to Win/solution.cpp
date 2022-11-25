#include <array>
#include <functional>
#include <iostream>
#include <map>
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
  while (T--) {
    long long N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    map<long long, long long> m;
    auto solve = yc([&](auto _solve, long long num) -> long long {
      if (m.find(num) != m.end()) {
        return m[num];
      }
      long long res = 1e15;
      if (num < 0) {
        return m[num] = 1e15;
      }
      if (num == 0) {
        return m[num] = 0;
      }
      if (num == 1) {
        return m[num] = D;
      }
      if (num == 2) {
        return m[num] = min(2 * D, D + A);
      }
      if (num <= 1e18 / D) {
        res = num * D;
      }
      for (long long i = num - 2; i <= num + 2; i++) {
        if (i % 2 == 0) {
          res = min(res, A + D * llabs(num - i) + _solve(i / 2));
        }

        if (i % 3 == 0) {
          res = min(res, B + D * llabs(num - i) + _solve(i / 3));
        }

        if (i % 5 == 0) {
          res = min(res, C + D * llabs(num - i) + _solve(i / 5));
        }
      }
      return m[num] = res;
    });
    cout << solve(N) << '\n';
  }
}
