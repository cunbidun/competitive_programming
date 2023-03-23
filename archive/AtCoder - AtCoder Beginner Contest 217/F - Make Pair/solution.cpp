/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-05 15:56:39 CST
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

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const int MOD = 998244353;
  auto mint = mod_int(MOD);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> g(2 * N);
  vector<vector<int>> is_good(2 * N, vector<int>(2 * N, 0));
  vector<vector<int>> nCk(N + 1, vector<int>(N + 1));
  nCk[1][0] = 1;
  nCk[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    nCk[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      nCk[i][j] = mint.add(nCk[i - 1][j - 1], nCk[i - 1][j]);
    }
  }
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;
    A--, B--;
    g[B].push_back(A);
    is_good[A][B] = 1;
    is_good[B][A] = 1;
  }
  vector<vector<int>> f(2 * N, vector<int>(2 * N, -1));
  int ans = yc([&](auto solve, int l, int r) -> int {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (l + 1 == r) {
      return f[l][r] = is_good[l][r];
    }
    if (l == r + 1) {
      return f[l][r] = 1;
    }
    f[l][r] = 0;
    for (int i : g[r]) {
      assert(i < r);
      if (l <= i && (r - i + 1) % 2 == 0) {
        if (i == l) {
          f[l][r] = mint.add(f[l][r], solve(l + 1, r - 1));
        } else {
          int ll = (i - 1 - l + 1) / 2;
          int rr = (r - i + 1) / 2;
          f[l][r] = mint.add(f[l][r], mint.mul(mint.mul(solve(l, i - 1), solve(i + 1, r - 1)), nCk[ll + rr][ll]));
        }
      }
    }
    return f[l][r];
  })(0, 2 * N - 1);
  assert(ans >= 0);
  cout << ans << '\n';
}
