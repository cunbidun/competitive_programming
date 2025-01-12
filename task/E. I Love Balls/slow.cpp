#include <bits/stdc++.h>
using namespace std;
long long t, n, k, s1, s2, a, b, mod = 1e9 + 7;
long long ksm(long long x, long long y) {
  if (!y)
    return 1;
  long long q = ksm(x, y >> 1);
  if (y & 1)
    return q * q % mod * x % mod;
  return q * q % mod;
}
int main() {
  cin >> t;
  long long x;
  while (t--) {
    cin >> n >> k;
    s1 = s2 = 0;
    for (int i = 1; i <= k; i++) {
      cin >> x;
      s1 = (s1 + x) % mod;
    }
    for (int i = k; i < n; i++) {
      cin >> x;
      s2 = (s2 + x) % mod;
    }
    a = (s2 * ((n - k + 1) / 2) % mod * ksm(n - k, mod - 2) + s1 * ((n - k + 2) / 2) % mod * ksm(n - k + 1, mod - 2)) %
        mod;
    b = (s1 + s2 - a + mod) % mod;
    printf("%lld %lld\n", a, b);
  }
  return 0;
}
