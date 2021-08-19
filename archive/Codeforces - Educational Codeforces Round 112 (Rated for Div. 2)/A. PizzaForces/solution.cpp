#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long N;
    cin >> N;
    long long ans = 1e18;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        long long x = max(0LL, N - i * 8 - j * 10);
        ans = min(ans, (x + 5) / 6 * 15 + i * 20 + j * 25);
      }
    }
    cout << ans << '\n';
  }
}
