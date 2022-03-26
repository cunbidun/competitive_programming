#ifdef __APPLE__
#include <iostream>
#include <vector>
#else
#include <bits/stdc++.h>
#endif

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    string s;
    cin >> s;
    int sum = 0;
    for (int i = 0; i < (int)s.size(); i++) {
      sum += (s[i] - '0');
    }
    sum %= 9;
    sum = 9 - sum;
    sum %= 9;
    if (sum == 0) {
      cout << s[0] << '0';
      for (int i = 1; i < (int)s.size(); i++) {
        cout << s[i];
      }
      cout << '\n';
      continue;
    }
    int pos = s.size();
    for (int i = (int)s.size() - 1; i >= 0; i--) {
      if (s[i] - '0' > sum) {
        pos = i;
      }
    }
    for (int i = 0; i < pos; i++) {
      cout << s[i];
    }
    cout << sum;
    for (int i = pos; i < (int)s.size(); i++) {
      cout << s[i];
    }
    cout << '\n';
  }
}
