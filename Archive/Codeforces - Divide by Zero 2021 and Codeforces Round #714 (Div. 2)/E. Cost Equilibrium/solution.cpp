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
  vector<int> f(1e5 + 1, 1);
  f[0] = 1;
  for (int i = 1; i <= 1e5; i++) {
    f[i] = op.mul(f[i - 1], i);
  }
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << '\n';
    return 0;
  }
  long long s = 0;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s % n != 0) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> l, u;
  int e = 0;
  for (int i : a) {
    if (i < s / n) {
      l.push_back(i);
    } else if (i > s / n) {
      u.push_back(i);
    } else {
      e++;
    }
  }
  if (e == n) {
    cout << 1 << '\n';
    return 0;
  }
  sort(l.begin(), l.end());
  sort(u.begin(), u.end());
  int lower = f[(int)l.size()];
  int cnt = 1;
  for (int i = 1; i < (int)l.size(); i++) {
    if (l[i] == l[i - 1]) {
      cnt++;
    } else {
      lower = op.div(lower, f[cnt]);
      cnt = 1;
    }
  }
  lower = op.div(lower, f[cnt]);

  int upper = f[(int)u.size()];
  cnt = 1;
  for (int i = 1; i < (int)u.size(); i++) {
    if (u[i] == u[i - 1]) {
      cnt++;
    } else {
      upper = op.div(upper, f[cnt]);
      cnt = 1;
    }
  }
  upper = op.div(upper, f[cnt]);

  int ee = e;
  e = op.div(f[n], op.mul(f[e], f[n - e]));

  if (l.size() == 1) {
    cout << op.mul(n - ee, op.mul(upper, e)) << '\n';
    return 0;
  }
  if (u.size() == 1) {
    cout << op.mul(n - ee, op.mul(lower, e)) << '\n';
    return 0;
  }
  cout << op.mul(op.mul(2, e), op.mul(lower, upper)) << '\n';
}
