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
    vector<int> l;
    for (int i = 0; i < (int)s.size(); i++) {
      if (s[i] == t[0]) {
        l.push_back(i);
      }
    }
    vector<int> cnt(2, 1e9);
    for (int i : l) {
      cnt[i % 2] = min(cnt[i % 2], i);
    }
    auto cal = [&](int c) -> int {
      if (cnt[c] == 1e9) {
        return 0;
      }
      int p = 0;
      for (int i = cnt[c]; i < (int)s.size(); i++) {
        if (t[p] == s[i] && i % 2 == c) {
          p++;
          if (p == (int)t.size()) {
            return (((int)s.size() - i + 1) % 2 == 0);
          }
          c = 1 - c;
        }
      }
      return 0;
    };
    int ok = 0;
    ok |= cal(0);
    ok |= cal(1);
    cout << ((ok) ? "YES" : "NO") << '\n';
  }
}
