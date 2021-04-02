#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (n % 2 == 0) {
      if (k % n == 0) {
        cout << n << "\n";
      } else {
        cout << k % n << "\n";
      }
    } else {
      int p = (k % n == 0) ? n : k % n;
      p = (p + (k - 1) / ((n - 1) / 2));
      p = (p % n == 0) ? n : p % n;
      cout << p << "\n";
    }
  }
}
