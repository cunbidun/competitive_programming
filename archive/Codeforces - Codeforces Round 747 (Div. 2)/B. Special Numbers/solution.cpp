#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int MOD = 1e9 + 7;
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    int ans = 0;
    for (int i = 0; i < 30; i++) {
      if ((K >> i) & 1) {
        int cur = 1;
        for (int j = 0; j < i; j++) {
          cur = (1LL * cur * N) % MOD;
        }
        ans = (ans + cur) % MOD;
      }
    }
    cout << ans << '\n';
  }
}
