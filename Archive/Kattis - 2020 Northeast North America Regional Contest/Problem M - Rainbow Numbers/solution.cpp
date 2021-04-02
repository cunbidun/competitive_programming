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
} op(998244353);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string l, u;
  cin >> l >> u;
  auto solve = [&](string s) {
    if (s.size() == 1) {
      return s[0] - '0';
    }
    int ans = 0;
    for (int i = 1; i < (int)s.size(); i++) {
      int p = op.pow(9, (int)s.size() - i - 1);
      ans = op.add(ans, op.mul(9, p));
    }
    int p = op.pow(9, (int)s.size() - 1);
    ans = op.add(ans, op.mul(s[0] - '0' - 1, p));
    // cout << ans << '\n';
    function<int(int, int up)> cal = [&](int i, int up) {
      if (i == s.size()) {
        return 1;
      }
      int cur = s[i] - '0';
      if (cur == up) {
        if (cur == 0) {
          return 0;
        }
        int p = op.pow(9, (int)s.size() - i - 1);
        return op.mul(cur, p);
      }
      if (up > cur) {
        int p = op.pow(9, (int)s.size() - i - 1);
        int res = op.mul(cur, p);
        return op.add(res, cal(i + 1, cur));
      }
      // up < cur
      int p = op.pow(9, (int)s.size() - i - 1);
      int res = op.mul(cur - 1, p);
      return op.add(res, cal(i + 1, cur));
    };

    // cout << ans << '\n';
    return op.add(ans, cal(1, s[0] - '0'));
  };
  int f = solve(l);
  int s = solve(u);
  int ok = 1;
  for (int i = 0; i < (int)l.size(); i++) {
    if (l[i] == l[i - 1]) {
      ok = 0;
    }
  }

  // cout << f << ' ' << s << ' ' << ok << '\n';
  cout << op.add(op.sub(s, f), ok) << '\n';
}
