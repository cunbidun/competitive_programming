#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int M = 1e6 + 5;
  vector<int> f(M, 1);
  for (int i = 6; i <= M - 1; i++) {
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        f[i] = max(f[i], f[(i - j) / j] + 1);
        if (i / j != j && i / j < i / 2) {
          int m = i / j;
          f[i] = max(f[i], f[(i - m) / m] + 1);
        }
      }
    }
  }
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    int ans = 1;
    for (int i = 3; i < N / 2; i++) {
      if (N % i == 0) {
        ans = max(ans, f[(N - i) / i] + 1);
      }
    }
    cout << ans << '\n';
  }
}
