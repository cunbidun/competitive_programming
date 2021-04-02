#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k1, k2, w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if (w * 2 < (k1 + k2) && b * 2 < 2 * n - k1 - k2) {
      cout << "YES\n";
    } else {
      if (w * 2 > (k1 + k2) || b * 2 > 2 * n - k1 - k2) {
        cout << "NO\n";
      } else {
        if ((k1 + k2) % 2 == 1) {
          cout << "NO\n";
        } else {
          cout << "YES\n";
        }
      }
    }
  }
}
