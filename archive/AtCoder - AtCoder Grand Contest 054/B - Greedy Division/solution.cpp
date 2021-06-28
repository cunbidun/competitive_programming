#include <bits/stdc++.h>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int MOD) {
    this->MOD = MOD;
  }
  int add(int x, int y) {
    return ((x + y) >= MOD ? x + y - MOD : x + y);
  }
  int sub(int x, int y) {
    return ((x - y) < 0 ? x - y + MOD : x - y);
  }
  int mul(int x, int y) {
    return (int)((1LL * x * y) % MOD);
  }
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
  int inv(int x) {
    return pow(x, MOD - 2);
  }
  int div(int x, int y) {
    return mul(x, inv(y));
  }
} o(998244353);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  int s = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % 2) {
    cout << 0 << '\n';
    return 0;
  }
  vector<vector<int>> f(N + 1, vector<int>(s + 1));
  vector<vector<int>> g(N + 1, vector<int>(s + 1));
  f[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    g = f;
    for (int j = 1; j <= N; j++) {
      for (int k = 1; k <= s; k++) {
        f[j][k] = g[j][k];
        if (k >= a[i]) {
          f[j][k] = o.add(f[j][k], g[j - 1][k - a[i]]);
        }
      }
    }
  }
  vector<int> p(N + 1);
  p[0] = 1;
  for (int i = 1; i <= N; i++) {
    p[i] = o.mul(p[i - 1], i);
  }
  int ans = 0;
  for (int i = 1; i <= N - 1; i++) {
    int tmp = o.mul(f[i][s / 2], o.mul(p[i], p[N - i]));
    ans = o.add(ans, tmp);
  }
  cout << ans << '\n';
}
