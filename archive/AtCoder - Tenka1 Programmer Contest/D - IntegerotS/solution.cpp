#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, K;
  cin >> N >> K;
  vector<array<int, 2>> a(N);
  long long ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> a[i][0] >> a[i][1];
    if ((K | a[i][0]) == K) {
      ans += a[i][1];
    }
  }
  int mask = 0;
  for (int i = 29; i >= 0; i--) {
    if ((K >> i) & 1) {
      long long res = 0;
      for (auto [num, u] : a) {
        if (((num >> i) | (mask >> i)) == (mask >> i)) {
          res += u;
        }
      }
      ans = max(ans, res);
      mask |= (K & (1 << i));
    }
  }
  cout << ans << '\n';
}
