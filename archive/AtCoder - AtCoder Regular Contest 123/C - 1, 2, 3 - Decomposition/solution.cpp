/**
 *  author: cunbidun
 *  created: Friday, 2022-12-23 11:27:03 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int need = 0;
    while (!s.empty()) {
      int last = s.back() - '0';
      if (need < 2 && 1 && 1 <= last && last <= 3) {
        need = 1;
      } else if (need < 3 && 2 <= last && last <= 6) {
        need = 2;
      } else if (3 <= last && last <= 9) {
        need = 3;
      } else {
        need = 4;
        break;
      }
      s.pop_back();
    }
    if (s.empty()) {
      cout << need << '\n';
      continue;
    }
    int sub = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      int current = s[i] - '0' - sub;
      if (current == 3) {
        need = 5;
        break;
      }
      if (current < 3) {
        sub = 1;
      } else {
        sub = 0;
      }
    }
    cout << need << '\n';
  }
}
