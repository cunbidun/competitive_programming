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
    int n = (int)s.size();
    vector<vector<int>> nxt(n, vector<int>(26, -1));
    vector<vector<int>> p(26, vector<int>());
    vector<int> ch(26);
    for (int i = 0; i < n; i++) {
      p[s[i] - 'a'].push_back(i);
      ch[s[i] - 'a'] = 1;
    }
    nxt[n - 1][s.back() - 'a'] = n - 1;
    for (int i = (int)s.size() - 2; i >= 0; i--) {
      for (int j = 0; j < 26; j++) {
        nxt[i][j] = nxt[i + 1][j];
      }
      nxt[i][s[i] - 'a'] = i;
    }
    vector<int> done(26, 0);
    int cur = -1;
    auto check = [&](int c) -> int {
      auto i = *upper_bound(p[c].begin(), p[c].end(), cur);
      bool ok = 1;
      for (int j = 0; j < 26; j++) {
        if (ch[j] && !done[j]) {
          ok &= (nxt[i][j] != -1);
        }
      }
      if (ok == 1) {
        done[c] = 1;
        cur = i;
      }
      return ok;
    };

    string ans = "";
    for (int i = 0; i < 26; i++) {
      for (int c = 25; c >= 0; c--) {
        if (!ch[c] || done[c]) {
          continue;
        }
        if (check(c)) {
          cout << (char)(c + 'a');
          break;
        }
      }
    }
    cout << '\n';
  }
}
