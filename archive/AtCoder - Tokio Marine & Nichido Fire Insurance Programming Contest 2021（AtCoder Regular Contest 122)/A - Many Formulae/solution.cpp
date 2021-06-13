#include <bits/stdc++.h>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int _MOD) {
    this->MOD = _MOD;
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
} o(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> c(N + 1, vector<int>(2));
  vector<vector<int>> f(N + 1, vector<int>(2));
  f[1][1] = a[1];
  c[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    f[i][0] = o.add(f[i - 1][1], o.sub(o.mul(-a[i], c[i - 1][1]), 0));
    f[i][1] = o.add(f[i - 1][0], f[i - 1][1]);
    f[i][1] = o.add(f[i][1], o.mul(a[i], c[i - 1][0]));
    f[i][1] = o.add(f[i][1], o.mul(a[i], c[i - 1][1]));
    c[i][0] = c[i - 1][1];
    c[i][1] = o.add(c[i - 1][0], c[i - 1][1]);
  }
  cout << o.add(f[N][0], f[N][1]) << '\n';
}
