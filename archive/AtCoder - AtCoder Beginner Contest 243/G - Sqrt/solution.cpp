/**
 *  author: cunbidun
 *  created: Monday, 2023-04-17 21:15:55 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  vector<long long> f(1e5);

  f[1] = 1;
  int MX = 1 << 16;
  for (int i = 2; i <= MX; i++) {
    for (int j = 1; j * j <= i; j++) {
      f[i] += f[j];
    }
  }
  for (int i = 2; i <= MX; i++) {
    f[i] += f[i - 1];
  }
  // cout << f[MX] << '\n';

  while (T--) {
    long long X;
    cin >> X;
    long long ans = 0;
    long long SQRT = sqrtl(X);
    for (long long i = 1;; i++) {
      long long lower = i * i;
      long long upper = min(SQRT, (i + 1) * (i + 1) - 1);
      long long num = upper - lower + 1;
      // cout << i << ' ' << lower << ' ' << upper << '\n';
      ans += num * f[i];
      if (SQRT == upper) {
        break;
      }
    }
    cout << ans << '\n';
  }
}
