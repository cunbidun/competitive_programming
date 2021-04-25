#include <bits/stdc++.h>

using namespace std;

int prefix_function(string s) {
  int n = (int)s.length();
  vector<int> pi(n);
  int mx = 0;
  int ch = 0;
  for (int i = 1; i < n; i++) {
    int j = pi[i - 1];
    while (j > 0 && s[i] != s[j]) {
      j = pi[j - 1];
    }
    if (s[i] == s[j]) {
      j++;
    }
    pi[i] = j;
    if (s[i] == '#') {
      ch = 1;
    }
    if (ch) {
      mx = max(mx, pi[i]);
    }
  }
  return mx;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  vector<string> l;
  vector<vector<int>> pi;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    l.push_back(s);
  }
  int ans = 0;
  for (int i = 0; i < l[0].size(); i++) {
    string tmp = "";
    for (int j = i; j < l[0].size(); j++) {
      tmp += l[0][j];
    }
    int res = 1e9;
    for (int k = 0; k < t; k++) {
      res = min(res, prefix_function(tmp + '#' + l[k]));
    }
    ans = max(ans, res);
  }
  cout << ans << '\n';
}
