#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    int S = (sqrt(Z) + 1) * 2;

    auto check = [&](int n, int m) -> bool {
      long long f = n / K;
      if (m < f) {
        return 1LL * (1 + m) * m / 2 * K >= 1LL * Z;
      }
      long long full = 1LL * (1 + f) * f / 2 * K;
      return full + n * (m - f) >= 1LL * Z;
    };

    long long ans = 1e18;

    for (int n = 1; n <= S; n++) {
      int l = 1, r = 1e8;
      while (l < r) {
        int m = (l + r) / 2;
        if (check(n, m)) {
          r = m;
        } else {
          l = m + 1;
        }
      }
      if (check(n, l)) {
        ans = min(ans, 1LL * n * X + 1LL * l * Y);
      }
    }

    for (int m = 1; m <= S; m++) {
      int l = 1, r = 1e8;
      while (l < r) {
        int n = (l + r) / 2;
        if (check(n, m)) {
          r = n;
        } else {
          l = n + 1;
        }
      }
      if (check(l, m)) {
        ans = min(ans, 1LL * l * X + 1LL * m * Y);
      }
    }

    cout << ans << '\n';
  }
}
