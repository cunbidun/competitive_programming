/**
 *  author: cunbidun
 *  created: Thursday, 2023-09-14 21:08:42 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

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
  int N, M;
  cin >> N >> M;
  vector<int> f(3 * N + 1);
  vector<int> inv(3 * N + 1);
  vector<int> suff(3 * N + 2);
  vector<int> pref(3 * N + 2);
  mod_int mint(M);
  f[0] = 1;
  suff[3 * N + 1] = 1;
  pref[0] = 1;
  inv[0] = 1;
  for (int i = 1; i <= 3 * N; i++) {
    f[i] = mint.mul(f[i - 1], i);
    pref[i] = mint.mul(f[i], pref[i - 1]);
  }
  for (int i = 3 * N; i >= 0; i--) {
    suff[i] = mint.mul(f[i], suff[i + 1]);
  }
  int INV = mint.inv(pref[3 * N]);
  for (int i = 1; i <= 3 * N; i++) {
    inv[i] = mint.mul(mint.mul(INV, pref[i - 1]), suff[i + 1]);
  }
  auto C = [&](int n, int k) -> int {
    assert(n >= k);
    return mint.mul(f[n], mint.mul(inv[k], inv[n - k]));
  };
  int zero = 1;
  int one = mint.mul(2, f[2 * N]);
  one = mint.sub(one, f[N]);
  one = mint.sub(one, zero);
  int two = mint.mul(2, mint.mul(f[2 * N], mint.mul(f[N], C(2 * N, N))));
  int bad = 0;
  for (int i = 0; i <= N; i++) {
    int tmp = C(N, i);
    int res = mint.mul(mint.mul(tmp, tmp), f[N]);
    res = mint.mul(res, mint.mul(C(2 * N - i, N), f[N]));
    bad = mint.add(bad, mint.mul(res, f[N]));
  }
  two = mint.sub(two, bad);
  two = mint.sub(two, one);
  two = mint.sub(two, zero);
  int three = mint.sub(f[3 * N], mint.add(mint.add(zero, one), two));
  int ans = 0;
  ans = mint.add(ans, one);
  ans = mint.add(ans, mint.mul(2, two));
  ans = mint.add(ans, mint.mul(3, three));
  cout << ans << '\n';
}
