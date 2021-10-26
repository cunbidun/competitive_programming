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
    for (int i = 0; i < N; i++) {
      char c;
      cin >> c;
      if (c != '0') {
        ans += c - '0';
        if (i != N - 1) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
