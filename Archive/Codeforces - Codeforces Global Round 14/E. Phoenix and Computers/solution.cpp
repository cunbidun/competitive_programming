#include <bits/stdc++.h>

using namespace std;

struct modInt {
  int MOD;

  modInt(int MOD) {
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
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  modInt op(m);
  vector<vector<int>> f(n + 1, vector<int>(n + 1));

  vector<vector<int>> C(500, vector<int>(500));
  vector<int> p(500);
  p[0] = 1;
  for (int i = 1; i < 500; i++) {
    p[i] = op.mul(p[i - 1], 2);
  }
  C[1][0] = C[1][1] = 1;
  for (int i = 2; i < 500; i++) {
    C[i][0] = 1;
    for (int j = 1; j <= i; j++) {
      C[i][j] = op.add(C[i - 1][j - 1], C[i - 1][j]);
    }
  }
  f[1][1] = 1;
  f[2][2] = 2;
  for (int i = 3; i <= n; i++) {
    for (int j = i / 2 + 1; j < n; j++) {
      for (int k = 2; k < i; k++) {
        int l = i - k;
        int w = op.mul(op.mul(C[j][l], f[k - 1][j - l]), p[l - 1]);
        f[i][j] = op.add(f[i][j], w);
      }
    }
    f[i][i] = p[i - 1];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = op.add(ans, f[n][i]);
  }
  cout << ans << '\n';
}
