/**
 *  author: cunbidun
 *  created: Saturday, 2023-05-20 14:59:02 CDT
 **/
#include <array>
#include <bitset>
#include <cassert>
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
  while (T--) {
    auto ask = [](int l, int r) -> int {
      cout << "? " << l << ' ' << r << endl;
      int x;
      cin >> x;
      return x;
    };
    int N;
    cin >> N;
    vector<vector<int>> f(N + 1, vector<int>(N + 1, -1));
    auto find = yc([&](auto _find, int l, int r) -> int {
      if (f[l][r] != -1) {
        return f[l][r];
      }
      if (l == r) {
        return f[l][r] = l;
      }
      if (l + 1 == r) {
        if (ask(l, r) == 1) {
          return f[l][r] = l;
        } else {
          return f[l][r] = r;
        }
      }
      int m = (l + r) / 2;
      int pl = _find(l, m);
      int pr = _find(m + 1, r);
      if (pl + 1 == pr) {
        if (ask(pl, pr) == 1) {
          return f[l][r] = pl;
        } else {
          return f[l][r] = pr;
        }
      }
      if (ask(pl, pr - 1) == ask(pl, pr)) {
        return f[l][r] = pr;
      } else {
        return f[l][r] = pl;
      }
    });
    int ans = find(1, N);
    cout << "! " << ans << endl;
  }
}
