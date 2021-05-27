#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<vector<int>> a;
  int mx = 0;
  while (1) {
    vector<int> cur;
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == 'R' && s[i + 1] == 'L') {
        cur.push_back(i);
        s[i] = 'L';
        s[i + 1] = 'R';
        i++;
      }
    }
    if (cur.size() == 0) {
      break;
    }
    a.push_back(cur);
    mx += cur.size();
  }
  if (k < a.size() || mx < k) {
    cout << -1 << '\n';
    return 0;
  }
  int idx = 0;
  for (int i = 0; i < (int)a.size(); i++) {
    if (k == (int)a.size() - i) {
      k--;
      cout << a[i].size() - idx << ' ';
      for (int j = idx; j < (int)a[i].size(); j++) {
        cout << a[i][j] + 1 << ' ';
      }
      idx = 0;
      cout << '\n';
    } else {
      k--;
      cout << 1 << ' ' << a[i][idx] + 1 << '\n';
      idx++;
      if (idx != (int)a[i].size()) {
        i--;
      } else {
        idx = 0;
      }
    }
  }
}
