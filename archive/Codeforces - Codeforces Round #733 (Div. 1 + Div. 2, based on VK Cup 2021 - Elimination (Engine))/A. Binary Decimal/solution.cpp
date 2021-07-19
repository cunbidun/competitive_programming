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
    int ans = 0;
    while (N) {
      ans = max(ans, N % 10);
      N /= 10;
    }
    cout << ans << '\n';
  }
}
