#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, C;
    cin >> R >> C;
    vector<vector<int>> a(R + 1, vector<int>(C + 1, 0));
    int cnt = 0;
    for (int i = 1; i <= R; i++) {
      for (int j = 1; j <= C; j++) {
        char x;
        cin >> x;
        if (x == '.') {
          a[i][j] = 0;
        } else {
          a[i][j] = 1;
          cnt++;
        }
      }
    }
    if (cnt == 0) {
      cout << "Possible\n";
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          cout << '.';
        }
        cout << '\n';
      }
    } else if (R > 1 && C > 1) {
      cout << "Possible\n";
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          cout << '^';
        }
        cout << '\n';
      }
    } else {
      cout << "Impossible\n";
    }
  }
}
