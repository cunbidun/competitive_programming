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
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<vector<int>>> f(n + 2, vector<vector<int>>(k + 2, vector<int>(2)));
    for (int i = 0; i <= n + 1; i++) {
      f[i][1][0] = 1;
      f[i][1][1] = 1;
    }
    for (int i = 1; i <= k; i++) {
      f[n + 1][i][0] = 1;
      f[0][i][1] = 1;
    }
    for (int j = 2; j <= k; j++) {
      for (int i = n; i >= 1; i--) {
        f[i][j][0] = op.add(f[i + 1][j][0], f[i - 1][j - 1][1]);
      }
      for (int i = 1; i <= n; i++) {
        f[i][j][1] = op.add(f[i - 1][j][1], f[i + 1][j - 1][0]);
      }
    }
    // cout << f[3][2][0] << '\n';
    cout << f[1][k][0] << "\n";
  }
}
