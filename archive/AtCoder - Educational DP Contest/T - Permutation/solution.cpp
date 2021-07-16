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
} o(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  string s;
  cin >> s;
  vector<vector<int>> f(N + 1, vector<int>(N + 1));
  f[0][1] = 1;
  for (int i = 1; i < N; i++) {
    if (s[i - 1] == '<') {
      for (int j = 1; j <= i + 1; j++) {
        f[i][j] = o.add(f[i][j - 1], f[i - 1][j - 1]);
      }
    } else {
      for (int j = i + 1; j >= 1; j--) {
        f[i][j] = o.add(f[i][j + 1], f[i - 1][j]);
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = o.add(ans, f[N - 1][i]);
  }
  cout << ans << '\n';
}
