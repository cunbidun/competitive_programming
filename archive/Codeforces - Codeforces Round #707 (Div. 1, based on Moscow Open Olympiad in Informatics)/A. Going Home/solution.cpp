#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<vector<int>> cnt(2500001, vector<int>());
  vector<int> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]].push_back(i);
    if ((int)cnt[a[i]].size() == 4) {
      cout << "YES\n";
      for (int j : cnt[a[i]]) {
        cout << j + 1 << '\n';
      }
      return 0;
    }
    if ((int)cnt[a[i]].size() == 2) {
      l.push_back(a[i]);
    }
  }
  if ((int)l.size() >= 2) {
    cout << "YES\n";
    cout << cnt[l[0]][0] + 1 << ' ' << cnt[l[1]][0] + 1 << ' ' << cnt[l[0]][1] + 1 << ' ' << cnt[l[1]][1] + 1 << '\n';
    return 0;
  }
  if ((int)l.size() == 1) {
    int num = l[0];
    for (int i = 1; i <= num - 1; i++) {
      if (num - i >= 1 && num + i <= 2500000) {
        if (!cnt[num - i].empty() && !cnt[num + i].empty()) {
          cout << "YES\n";
          cout << cnt[num - i][0] + 1 << ' ' << cnt[num + i][0] + 1
               << ' ' << cnt[l[0]][1] + 1 << ' ' << cnt[l[0]][0] + 1 << '\n';
          return 0;
        }
      }
    }
  }
  set<int> s;
  l.clear();
  for (int i = 0; i < n; i++) {
    if (s.size() == 6000) {
      break;
    }
    if (s.find(a[i]) == s.end()) {
      l.push_back(a[i]);
      s.insert(a[i]);
    }
  }
  vector<int> val(5000001);
  for (int i = 0; i < (int)l.size(); i++) {
    for (int j = i + 1; j < (int)l.size(); j++) {
      if (val[l[i] + l[j]] != 0) {
        cout << "YES\n";
        int f = val[l[i] + l[j]];
        int s = l[i] + l[j] - f;
        cout << cnt[f][0] + 1 << ' ' << cnt[s][0] + 1
             << ' ' << cnt[l[i]][0] + 1 << ' ' << cnt[l[j]][0] + 1 << '\n';
        return 0;
      }
      val[l[i] + l[j]] = l[i];
    }
  }
  cout << "NO\n";
}
