#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    string S, F;
    cin >> S >> F;
    int ans = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      int mn = 1e9;
      for (int j = 0; j < (int)F.size(); j++) {
        mn = min(mn, min(abs(F[j] - S[i]), 26 - abs(F[j] - S[i])));
      }
      ans += mn;
    }
    cout << ans << '\n';
  }
}
