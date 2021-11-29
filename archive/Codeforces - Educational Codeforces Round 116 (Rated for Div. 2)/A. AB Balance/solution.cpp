#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    if (s[0] != s.back()) {
      if (s[0] == 'a') {
        s[0] = 'b';
      } else {
        s[0] = 'a';
      }
    }

    cout << s << '\n';
  }
}
