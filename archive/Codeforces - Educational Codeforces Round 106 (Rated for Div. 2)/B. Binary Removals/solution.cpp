#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int d = 0;
    for (int i = 0; i <= (int)s.size(); i++) {
      vector<int> l;
      for (int j = 0; j < i; j++) {
        if (s[j] == '1') {
          l.push_back(j);
        }
      }
      for (int j = i; j < (int)s.size(); j++) {
        if (s[j] == '0') {
          l.push_back(j);
        }
      }
      int ok = 1;
      for (int j = 1; j < (int)l.size(); j++) {
        if (l[j] == l[j - 1] + 1) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        d = 1;
        break;
      }
    }
    if (d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
