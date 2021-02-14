#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    int ans = 1e9;
    for (int i = 0; i <= 10000; i++) {
      int c = b + i;
      if (c == 1) {
        continue;
      }
      int cnt = 0;
      int tmp = a;
      while (tmp != 0) {
        tmp /= c;
        cnt++;
      }
      ans = min(ans, cnt + i);
    }
    cout << ans << "\n";
  }
}
