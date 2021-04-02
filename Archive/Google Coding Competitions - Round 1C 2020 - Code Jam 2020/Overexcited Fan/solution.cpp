#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int X, Y;
    string S;
    cin >> X >> Y >> S;
    int ans = -1;
    if (abs(X) + abs(Y) <= 0) {
      ans = 0;
    } else {
      for (int i = 0; i < (int)S.size(); i++) {
        if (S[i] == 'E') {
          X++;
        }
        if (S[i] == 'W') {
          X--;
        }
        if (S[i] == 'N') {
          Y++;
        }
        if (S[i] == 'S') {
          Y--;
        }
        if (abs(X) + abs(Y) <= i + 1) {
          ans = i + 1;
          break;
        }
      }
    }
    if (ans == -1) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << ans << '\n';
    }
  }
}
