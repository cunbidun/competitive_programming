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
  int T;
  cin >> T;
  for (int t = 0; t < T; t++) {
    cout << "Case #" << t + 1 << ": ";
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int ans = 0;
    for (int i = 0; i < (N + 1) / 2; i++) {
      for (char c = 'a'; c < S[i]; c++) {
        ans = o.add(ans, o.pow(K, (N + 1) / 2 - i - 1));
      }
    }
    string tmp = "";
    for (int i = 0; i < (N + 1) / 2; i++) {
      tmp += S[i];
    }
    for (int i = N / 2 - 1; i >= 0; i--) {
      tmp += S[i];
    }
    if (tmp < S) {
      ans = o.add(ans, 1);
    }
    cout << ans << '\n';
  }
}
