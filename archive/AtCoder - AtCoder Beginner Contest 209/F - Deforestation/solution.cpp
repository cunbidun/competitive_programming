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
  vector<int> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> f(N + 2, vector<int>(N + 2));
  f[1][1] = 1;
  for (int i = 2; i <= N; i++) {
    if (a[i - 1] == a[i]) {
      int s = 0;
      for (int j = 1; j <= i - 1; j++) {
        s = o.add(s, f[i - 1][j]);
      }
      for (int j = 1; j <= i; j++) {
        f[i][j] = s;
      }
    } else {
      if (a[i - 1] < a[i]) {
        for (int j = i; j >= 1; j--) {
          f[i][j] = o.add(f[i][j + 1], f[i - 1][j]);
        }
      } else {
        for (int j = 1; j <= i; j++) {
          f[i][j] = o.add(f[i][j - 1], f[i - 1][j - 1]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans = o.add(ans, f[N][i]);
  }
  cout << ans << '\n';
}
