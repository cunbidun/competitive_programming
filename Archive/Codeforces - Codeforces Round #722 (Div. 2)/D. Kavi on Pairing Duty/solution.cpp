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
} o(998244353);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> lp;
  vector<int> pr;
  auto sieve = [&lp, &pr](int N) {
    lp.assign(N, 0);
    for (int i = 2; i < N; ++i) {
      if (lp[i] == 0) {
        lp[i] = i;
        pr.push_back(i);
      }
      for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] < N; ++j) {
        lp[i * pr[j]] = pr[j];
      }
    }
  };

   sieve(1000005);
  vector<int> f(N + 1), s(N + 1);
  auto cal = [&](int i) -> int {
    int res = 1;
    while (i > 1) {
      int tmp = lp[i];
      int cnt = 0;
      while (i % tmp == 0) {
        cnt++;
        i /= tmp;
      }
      res *= (1 + cnt);
    }
    return res;
  };
  for (int i = 1; i <= N; i++) {
    f[i] = o.add(f[i], o.add(s[i - 1], cal(i)));
    s[i] = o.add(s[i - 1], f[i]);
  }
  cout << f[N] << '\n';
}
