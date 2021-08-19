#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N + 2), b(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    for (int i = N; i >= 1; i--) {
      a[i] += a[i + 1];
    }
    for (int i = 1; i <= N; i++) {
      cin >> b[i];
      b[i] += b[i - 1];
    }
    int ans = 2e9 + 7;
    for (int i = 1; i <= N; i++) {
      ans = min(ans, max(b[i - 1], a[i + 1]));
    }
    cout << ans << '\n';
  }
}
