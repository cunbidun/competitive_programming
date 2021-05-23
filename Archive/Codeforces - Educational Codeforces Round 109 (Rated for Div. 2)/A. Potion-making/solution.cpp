#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    int ans = 1000000;
    for (int i = 1; i <= 100; i++) {
      for (int j = 0; j <= 100; j++) {
        if (i * 100 == k * (i + j)) {
          ans = min(j + i, ans);
        }
      }
    }
    cout << ans << '\n';
  }
}
