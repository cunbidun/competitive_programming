#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int H, W;
    cin >> H >> W;
    string S;
    cin >> S;

    int x = H - 1, y = W - 1;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == 'D') {
        x--;
      }
      if (S[i] == 'R') {
        y--;
      }
    }
    long long ans = 1LL * H * W;
    int c = 1;
    int current_row = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == 'D') {
        // cout << current_row << ' ' << W - c << '\n';
        ans -= W - c;
        // current_row++;
      } else {
        if (S[i] == 'R') {
          c++;
        } else {
          if (y > 0) {
            y--;
            c++;
          } else {
            // cout << current_row << ' ' << W - c << '\n';
            ans -= W - c;
            // current_row++;
          }
        }
      }
    }

    c = 1;
    for (int i = 0; i < (int)S.size(); i++) {
      if (S[i] == 'R') {
        ans -= H - c;
      } else {
        if (S[i] == 'D') {
          c++;
        } else {
          if (x > 0) {
            x--;
            c++;
          } else {
            ans -= H - c;
          }
        }
      }
    }
    cout << ans << '\n';
  }
}
