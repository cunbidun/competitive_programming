#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    long long ans = 0;
    for (int q = 1;; q++) {
      if (1LL * q * (q + 2) > x || q + 1 > y) {
        break;
      }
      long long u = min(1LL * x, 1LL * q * (y + 1));
      ans += (u - 1LL * q * (q + 2)) / q + 1;
    }
    cout << ans << "\n";
  }
}
