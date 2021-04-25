#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      if (x != 2) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}
