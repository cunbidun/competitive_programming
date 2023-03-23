/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-19 00:21:18 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;
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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<array<long long, 2>> a(N);
  vector<vector<long long>> f(N + 2, vector<long long>(N + 2, -1));
  for (int i = 0; i < N; i++) {
    cin >> a[i][0];
    a[i][1] = i;
  }
  sort(a.begin(), a.end(), [](auto f, auto s) { return f[0] > s[0]; });

  cout << yc([&](auto solve, int l, int r) -> long long {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (l + r == N) {
      return f[l][r] = 0;
    }
    auto e = a[l + r];
    f[l][r] = max(solve(l + 1, r) + 1LL * e[0] * abs(l - e[1]), solve(l, r + 1) + 1LL * e[0] * abs((N - 1 - r) - e[1]));
    return f[l][r];
  })(0, 0)
       << '\n';
}
