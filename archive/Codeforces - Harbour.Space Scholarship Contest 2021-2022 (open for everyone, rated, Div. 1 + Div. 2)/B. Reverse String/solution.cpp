#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s, t;
    cin >> s >> t;
    auto check = [&](int i) {
      for (int j = 0; j <= (int)t.size(); j++) {
        string left = t.substr(0, j);
        string right = t.substr(j);
        reverse(right.begin(), right.end());
        if ((int)left.size() > i + 1 || (int)right.size() > i) {
          continue;
        }
        int ls = (int)left.size();
        int rs = (int)right.size();
        if (s.substr(i - ls + 1, ls) == left &&
            s.substr(i - rs, rs) == right) {
          return 1;
        }
      }
      return 0;
    };
    bool ok = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      if (check(i)) {
        ok = 1;
        break;
      }
    }
    if (ok) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
