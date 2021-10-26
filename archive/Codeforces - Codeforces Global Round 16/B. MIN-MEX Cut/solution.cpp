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
    int cnt = 0;
    vector<int> l;
    for (int i = 1; i < (int)s.size(); i++) {
      if (s[i] != s[i - 1]) {
        if (s[i - 1] == '0') {
          l.push_back(cnt);
        }
        cnt = 1;
      } else {
        cnt++;
      }
    }
    if (s.back() == '0') {
      l.push_back(cnt);
    }
    cout << min((int)l.size(), 2) << '\n';
  }
}
