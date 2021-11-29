#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    long long N, K;
    cin >> N >> K;

    long long ans = 0;
    long long cur = 1;
    long long tot = 1;

    while (cur <= min(N, K) && tot < N) {
      tot += cur;
      cur *= 2;
      ans++;
    }
    if (tot >= N) {
      cout << ans << '\n';
    } else {
      cout << ans + (N - tot + K - 1) / K << '\n';
    }
  }
}
