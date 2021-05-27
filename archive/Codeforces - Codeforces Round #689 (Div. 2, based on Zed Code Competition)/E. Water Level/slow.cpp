#include <bits/stdc++.h>

using namespace std;

int main() {
  long long l, k, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  for (int i = 1; i <= t; i++) {
    if (k + y <= r) {
      k += y;
    }
    k -= x;
    if (k < l) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
