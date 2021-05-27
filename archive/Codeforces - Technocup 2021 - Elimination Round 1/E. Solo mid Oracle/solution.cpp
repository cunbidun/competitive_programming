#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    auto cal = [&](int cal) -> long long {
      long long m = -(cal + 1) * a;
      long long p = b * d * cal * (cal + 1) / 2;
      return m + p;
    };

    if (a > b * c) {
      cout << -1 << '\n';
    } else {
      if (d > c) {
        cout << a << '\n';
      } else {
        int l = 1, r = c / d;
        while (l < r) {
          int m = (l + r + 1) / 2;
          // cout << m << ' ' << cal(m - 1) << ' ' << cal(m) << '\n';
          if (cal(m - 1) > cal(m)) {
            l = m;
          } else {
            r = m - 1;
          }
        }
        cout << max(a, -cal(l)) << '\n';
      }
    }
  }
}
