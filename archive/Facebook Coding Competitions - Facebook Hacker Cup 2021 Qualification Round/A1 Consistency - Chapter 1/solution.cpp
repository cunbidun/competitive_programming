#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  set<int> v = {'A', 'E', 'I', 'O', 'U'};

  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    string s;
    cin >> s;
    int ans = 1e9;
    for (char c = 'A'; c <= 'Z'; c++) {
      int res = 0;
      for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] != c) {
          if ((v.find(s[i]) == v.end()) ^ (v.find(c) == v.end())) {
            res++;
          } else {
            res += 2;
          }
        }
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
}
