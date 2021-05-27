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
  vector<int> P(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
  }
  int cur = 1;
  int ans = 0;
  for (int i = (int)P.size() - 1; i >= 0; i--) {
    int nxt = o.div(cur, o.div(P[i], 100));
    ans = o.add(ans, nxt);
    cur = nxt;
  }
  cout << ans << '\n';
}
