#include <bits/stdc++.h>

using namespace std;

// Code below this line will be copied.

int n, a[100];
int main() {
  cin >> n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int x = 1; x <= n - 2; x++) {
    for (int y = 1; x + y <= n - 1; y++) {
      int mx1 = 0, mx2 = 0;
      int mn = 1000000000;
      for (int i = 1; i <= x; i++) {
        mx1 = max(mx1, a[i]);
      }
      for (int i = x + 1; i <= x + y; i++) {
        mn = min(mn, a[i]);
      }
      for (int i = x + y + 1; i <= n; i++) {
        mx2 = max(mx2, a[i]);
      }
      if (mx1 == mx2 && mx1 == mn) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
