#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a > b) {
      cout << "NO\n";
      continue;
    }
    int c_a = 0, c_b = 0;
    int f = 0;
    for (int i = 0; i < 30; i++) {
      c_a += ((a >> i) & 1);
      c_b += ((b >> i) & 1);
      if (c_a < c_b) {
        f = 1;
        break;
      }
    }
    if (!f) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
