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
    cout << "Case #" << tt << ":\n";
    int R, C;
    cin >> R >> C;
    for (int i = 1; i <= 2 * R + 1; i++) {
      for (int j = 1; j <= 2 * C + 1; j++) {
        if (i <= 2 && j <= 2) {
          cout << ".";
        } else if (i % 2 == 1 && j % 2 == 1) {
          cout << "+";
        } else if (i % 2 == 0 && j % 2 == 0) {
          cout << ".";
        } else if (i % 2 == 0 && j % 2 == 1) {
          cout << "|";
        } else {
          cout << "-";
        }
      }
      cout << '\n';
    }
  }
}
