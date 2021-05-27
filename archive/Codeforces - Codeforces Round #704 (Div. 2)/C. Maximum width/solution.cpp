#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  string s, t;
  cin >> n >> m;
  cin >> s >> t;
  vector<vector<int>> prev(n, vector<int>(26, -1));
  prev[0][s[0] - 'a'] = 0;
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      prev[i][j] = prev[i - 1][j];
    }
    prev[i][s[i] - 'a'] = i;
  }
  int p = 0;
  vector<int> l;
  for (int i = 0; i < n; i++) {
    if (s[i] == t[p]) {
      l.push_back(i);
      p++;
    }
  }
  int ans = 0;
  for (int i = 1; i < (int)l.size(); i++) {
    ans = max(ans, l[i] - l[i - 1]);
  }
  int cur = n - 1;
  for (int i = m - 2; i >= 0; i--) {
    int nxt = prev[cur][t[i + 1] - 'a'];
    if (nxt == -1) {
      break;
    }
    ans = max(ans, nxt - l[i]);
    cur = nxt - 1;
  }
  cout << ans << "\n";
}
