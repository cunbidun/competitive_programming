#include <bits/stdc++.h>

using namespace std;

int main() {
  int l, u;
  cin >> l >> u;
  int ans = 0;
  for (int i = l; i <= u; i++) {
    int t = i;
    int cur = t % 10;
    t /= 10;
    int f = 1;
    while (t) {
      if (t % 10 == cur) {
        f = 0;
        break;
      }
      cur = t % 10;
      t /= 10;
    }
    ans += f;
  }
  cout << ans << '\n';
}
