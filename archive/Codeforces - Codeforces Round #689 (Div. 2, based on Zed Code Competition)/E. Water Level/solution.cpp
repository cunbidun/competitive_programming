#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long l, k, r, t, x, y;
  cin >> k >> l >> r >> t >> x >> y;
  if (x >= y) {
    if (k + y <= r) {
      k += y;
    }
    if (k - x < l) {
      cout << "No\n";
      return 0;
    }
    k -= x;
    long long diff = x - y;
    if (diff == 0) {
      cout << "Yes\n";
      return 0;
    }
    long long d = (k - l) / diff;
    if (d + 1 >= t) {
      cout << "Yes\n";
    } else {
      cout << "No\n";
    }
  } else {
    set<long long> s;
    long long d = 0;
    while (1) {
      long long c = (k - l) / x;
      d += c;
      k -= c * x;
      if (d >= t) {
        cout << "Yes\n";
        return 0;
      }
      if (s.find(k) != s.end()) {
        cout << "Yes\n";
        return 0;
      }
      s.insert(k);
      if (k + y > r) {
        cout << "No\n";
        return 0;
      }
      k += y;
    }
  }
}
