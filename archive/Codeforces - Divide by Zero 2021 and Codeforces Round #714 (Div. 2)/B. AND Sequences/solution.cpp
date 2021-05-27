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
  int t;
  cin >> t;
  vector<int> f(2e5 + 1, 1);
  f[0] = 1;
  for (int i = 1; i <= 2e5; i++) {
    f[i] = op.mul(f[i - 1], i);
  }
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int x = a[0];
    for (int i : a) {
      x &= i;
    }
    int cnt = 0;
    for (int i : a) {
      if (i == x) {
        cnt++;
      }
    }
    if (cnt < 2) {
      cout << 0 << '\n';
    } else {
      int o = op.mul(cnt, (cnt - 1));
      cout << op.mul(o, f[n - 2]) << '\n';
    }
  }
}
