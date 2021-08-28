#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int A, B, K;
  cin >> A >> B >> K;
  int ans = 0;
  for (int y = 0; y <= 1000; y++) {
    if (y * y * y < A) {
      continue;
    }
    if (B < y * y * y) {
      break;
    }
    for (int x = 0;; x++) {
      if (x * x < A) {
        continue;
      }
      if (x * x > B) {
        break;
      }
      if (abs(x * x - y * y * y) <= K) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}
