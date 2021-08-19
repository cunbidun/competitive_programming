#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int b = max(0, N - 1000);
    long long ans = -1e18;
    for (int i = b; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        ans = max(ans, 1LL * (i + 1) * (j + 1) - K * (a[i] | a[j]));
      }
    }
    cout << ans << '\n';
  }
}
