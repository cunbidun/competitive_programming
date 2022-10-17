#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
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
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  auto mint = mod_int(3);
  vector<int> f(N + 1);
  vector<int> cnt(N + 1);
  f[0] = 1;
  for (int i = 1; i <= N; i++) {
    int cur = i;
    cnt[i] = cnt[i - 1];
    while (cur % 3 == 0) {
      cur /= 3;
      cnt[i]++;
    }
    f[i] = mint.mul(f[i - 1], cur);
  }
  auto C = [&](int n, int k) -> int {
    if (cnt[n] - cnt[k] - cnt[n - k] > 0) {
      return 0;
    }
    return mint.div(f[n], mint.mul(f[k], f[n - k]));
  };
  int res = 0;
  for (int i = 0; i < N; i++) {
    char x;
    cin >> x;
    int num = 0;
    if (x == 'B') {
      num = 1;
    }
    if (x == 'R') {
      num = 2;
    }
    res = mint.add(res, mint.mul(num, C(N - 1, i)));
  }

  res %= 3;

  int ans = res;
  if (N % 2 == 0) {
    ans = (3 - res) % 3;
  }
  if (ans == 0) {
    cout << "W\n";
  } else if (ans == 1) {
    cout << "B\n";
  } else {
    cout << "R\n";
  }
}
