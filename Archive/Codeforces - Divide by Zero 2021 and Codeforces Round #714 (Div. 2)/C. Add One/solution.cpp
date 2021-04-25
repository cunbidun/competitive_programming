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

  int pow(int x, long long p) {
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
} op(1e9 + 7);
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> f(10, vector<int>(2e5 + 1, -1));

  function<int(int, int)> cal = [&](int i, int m) {
    if (f[i][m] != -1) {
      return f[i][m];
    }
    if (m == 0) {
      return f[i][m] = 1;
    }
    if (i < 9) {
      f[i][m] = cal(i + 1, m - 1);
    } else {
      f[i][m] = op.add(cal(0, m - 1), cal(1, m - 1));
    }
    return f[i][m];
  };
  for (int i = 0; i <= 9; i++) {
    cal(i, 2e5);
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m, ans = 0;
    cin >> n >> m;
    while (n) {
      ans = op.add(ans, cal(n % 10, m));
      n /= 10;
    };
    cout << ans << '\n';
  }
}
