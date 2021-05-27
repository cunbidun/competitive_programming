#include <bits/stdc++.h>

using namespace std;

struct mod_int {
  int MOD;

  mod_int(int MOD) { this->MOD = MOD; }

  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }

  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }

  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }

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

  int inv(int x) { return pow(x, MOD - 2); }

  int div(int x, int y) { return mul(x, inv(y)); }
} op(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<vector<int>> f(n + 1, vector<int>(3, 0));
  string s;
  cin >> s;
  int blocks = 1;
  for (int i = 1; i <= n; i++) {
    if (s[i - 1] == '?') {
      for (int j = 0; j < 3; j++) {
        f[i][j] = op.mul(f[i - 1][j], 3);
      }
      f[i][2] = op.add(f[i][2], f[i - 1][1]);
      f[i][1] = op.add(f[i][1], f[i - 1][0]);
      f[i][0] = op.add(f[i][0], blocks);
      blocks = op.mul(blocks, 3);
    } else {
      for (int j = 0; j < 3; j++) {
        f[i][j] = f[i - 1][j];
      }
      if (s[i - 1] == 'a') {
        f[i][0] = op.add(f[i][0], blocks);
      }
      if (s[i - 1] == 'b') {
        f[i][1] = op.add(f[i][1], f[i - 1][0]);
      }
      if (s[i - 1] == 'c') {
        f[i][2] = op.add(f[i][2], f[i - 1][1]);
      }
    }
    // cout << f[i][0].val() << ' ' << f[i][1].val() << ' ' << f[i][2].val()
    //      << '\n';
  }
  cout << f[n][2] << '\n';
}
