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
    int u = min(m, d);
    int s = u % dp;
    int c = u / dp;
    int e = u - dp;
    long long ans = 1LL * (e + s) * c / 2;
    cout << ans << '\n';
  }
}
