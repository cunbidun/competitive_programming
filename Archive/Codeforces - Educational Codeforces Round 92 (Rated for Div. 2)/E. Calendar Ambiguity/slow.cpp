#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int m, d, w;
    cin >> m >> d >> w;
    int dp = w / __gcd(w, d - 1);
    int u = min(d, m);
    long long ans = 0;
    for (int i = dp; i <= u; i += dp) {
      ans += u - i;
    }
    cout << ans << '\n';
  }
}
