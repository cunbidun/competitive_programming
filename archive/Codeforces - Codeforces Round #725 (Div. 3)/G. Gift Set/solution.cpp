#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x < y) {
      swap(x, y);
    }
    if (a < b) {
      swap(a, b);
    }
    if (a == b) {
      cout << min(x / a, y / a) << '\n';
      continue;
    }
    long long ans = (x - y) / (a - b);
    ans = min({ans, x / a, y / b});
    x -= ans * a;
    y -= ans * b;
    long long ans2 = min(x / (a + b), y / (a + b));
    x -= ans2 * (a + b);
    y -= ans2 * (a + b);
    if (x >= a && y >= b) {
      ans++;
    }
    cout << ans + 2 * ans2 << '\n';
  }
}
