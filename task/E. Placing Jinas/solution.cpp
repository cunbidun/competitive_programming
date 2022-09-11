#include <array>
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
  int MOD = 1e9 + 7;
  int N;
  cin >> N;
  vector<int> a(N + 2);
  for (int i = 0; i <= N; i++) {
    cin >> a[i];
  }
  mod_int mint(MOD);
  vector<int> p(4e5 + 1);
  // p[0] = 1;
  // for (int i = 1; i <= 4e5; i++) {
  //   p[i] = mint.mul(p[i - 1], 2);
  // }
  vector<int> f(2 * N + 1);
  f[0] = 1;
  for (int i = 1; i <= 2 * N; i++) {
    f[i] = mint.mul(f[i - 1], i);
  }
  int last = 0;
  auto C = [&](int n, int k) -> int { return mint.mul(f[n], mint.inv(mint.mul(f[k], f[n - k]))); };
  int ans = 0;
  for (int i = 1; i <= N + 1; i++) {
    if (a[i] != a[i - 1]) {
      ans = mint.add(ans, C(a[i - 1] + i - 2, i - 1));
      for (int j = last; j < i;   j++) {
        ans = mint.add(ans, C(a[i - 1] + j - 2, j - 1));
      }
      last = i;
    }
    if (a[i] == 0) {
      for (int j = 1; j < a[i - 1]; j++) {
        ans = mint.add(ans, C(a[i - 1] + j - 2, j - 1));
        cout << a[i - 1] << ' ' << j << ' ' << C(a[i - 1] + j - 2, j - 1) << '\n';
      }
      break;
    }
  }
  cout << ans << '\n';
}
