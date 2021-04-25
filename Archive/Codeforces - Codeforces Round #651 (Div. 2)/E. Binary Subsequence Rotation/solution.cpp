#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string s, t;
  cin >> s >> t;
  vector<set<int>> q(2);
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      q[s[i] - '0'].insert(i);
    }
  }
  if (q[0].size() != q[1].size()) {
    cout << -1 << '\n';
    return 0;
  }
  int ans = 0;
  while (!q[0].empty()) {
    ans++;
    int c = (*q[0].begin() > *q[1].begin());
    int p = -1;
    while (1) {
      auto it = q[c].lower_bound(p);
      if (it != q[c].end()) {
        p = *it;
      } else {
        break;
      }
      it = q[1 - c].upper_bound(p);
      if (it != q[1 - c].end()) {
        q[c].erase(p);
        p = *it;
        q[1 - c].erase(it);
      } else {
        break;
      }
    }
  }
  cout << ans << '\n';
}
