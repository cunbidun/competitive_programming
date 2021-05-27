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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(M);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int x;
      cin >> x;
      a[j].push_back(x);
    }
  }
  int ans = 0;
  int d = 1;
  for (int i = 1; i <= N; i++) {
    d = o.mul(d, i);
  }
  for (int i = 0; i < M; i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      a[i][j] = N - a[i][j] + 2;
    }
    int res = 1;
    sort(a[i].begin(), a[i].end());
    reverse(a[i].begin(), a[i].end());
    int cnt = 0;
    for (int j : a[i]) {
      res = o.mul(res, N - j + 1 - cnt);
      cnt++;
    }
    ans = o.add(ans, o.sub(d, res));
  }
  cout << o.div(ans, d) << '\n';
}

