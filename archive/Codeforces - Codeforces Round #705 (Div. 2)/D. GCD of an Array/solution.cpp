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
  const int N = 2e5 + 1;
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  int gcd = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    gcd = __gcd(a[i], gcd);
  }
  vector<multiset<int>> p(N, multiset<int>());
  vector<map<int, int>> t(N, map<int, int>());
  for (int i = 0; i < n; i++) {
    for (int j = 2; j * j <= a[i]; j++) {
      if (a[i] % j == 0) {
        int cnt = 0;
        while (a[i] % j == 0) {
          cnt++;
          a[i] /= j;
        }
        p[j].insert(cnt);
        t[i][j] = cnt;
      }
    }
    if (a[i] != 1) {
      p[a[i]].insert(1);
      t[i][a[i]] = 1;
    }
  }
  while (q--) {
    int i, x;
    cin >> i >> x;
    i--;
    int cur = 1;
    for (int j = 2; j * j <= x; j++) {
      int cnt = 0;
      if (x % j == 0) {
        while (x % j == 0) {
          cnt++;
          x /= j;
        }
        if (t[i].find(j) == t[i].end()) {
          t[i][j] = cnt;
          p[j].insert(cnt);
          if ((int)p[j].size() == n) {
            cur = op.mul(cur, pow(j, *p[j].begin()));
          }
        } else {
          int b = *p[j].begin();
          auto it = p[j].find(t[i][j]);
          p[j].erase(it);
          p[j].insert(t[i][j] + cnt);
          t[i][j] += cnt;
          if ((int)p[j].size() == n) {
            cur = op.mul(cur, pow(j, *p[j].begin() - b));
          }
        }
      }
    }
    if (x != 1) {
      int cnt = 1;
      int j = x;
      if (t[i].find(j) == t[i].end()) {
        t[i][j] = cnt;
        p[j].insert(cnt);
        if ((int)p[j].size() == n) {
          cur = op.mul(cur, pow(j, *p[j].begin()));
        }
      } else {
        int b = *p[j].begin();
        auto it = p[j].find(t[i][j]);
        p[j].erase(it);
        p[j].insert(t[i][j] + cnt);
        t[i][j] += cnt;
        if ((int)p[j].size() == n) {
          cur = op.mul(cur, pow(j, *p[j].begin() - b));
        }
      }
    }
    gcd = op.mul(gcd, cur);
    cout << gcd << '\n';
  }
}
