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
    cin >> X >> Y;
    vector<char> l;
    int done = 0;
    function<int(int, int, int)> solve = [&](int i, int x, int y) {
      if (done) {
      }
      if (x == 0 && y == 0) {
        for (char s : l) {
          cout << s;
        }
        done = 1;
        return 1;
      }
      if ((((x >> i) & 1) ^ ((y >> i) & 1)) == 0) {
        return 0;
      }
      if ((x >> i) & 1) {
        if (X > 0) {
          l.push_back('E');
        } else {
          l.push_back('W');
        }
        int ok = solve(i + 1, x - (1 << i), y);
        l.pop_back();
        if (!ok) {
          if (X > 0) {
            l.push_back('W');
          } else {
            l.push_back('E');
          }
          ok |= solve(i + 1, x + (1 << i), y);
          l.pop_back();
        }
        return ok;
      } else {
        if (Y > 0) {
          l.push_back('N');
        } else {
          l.push_back('S');
        }
        int ok = solve(i + 1, x, y - (1 << i));
        l.pop_back();
        if (!ok) {
          if (Y > 0) {
            l.push_back('S');
          } else {
            l.push_back('N');
          }
          ok = solve(i + 1, x, y + (1 << i));
          l.pop_back();
        }
        return ok;
      }
    };
    solve(0, max(-X, X), max(-Y, Y));
    if (!done) {
      cout << "IMPOSSIBLE";
    }
    cout << '\n';
  }
}
