#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = 0;
  int tot = 0;
  vector<int> cnt(n);
  for (int i = 1; i < (1 << n); i++) {
    vector<int> l;
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 1) {
        l.push_back(a[j]);
      }
    }
    int ok = 1;
    for (int j = 1; j < (int)l.size(); j++) {
      ok &= (l[j - 1] < l[j]);
    }
    if (ok) {
      mx = max((int)l.size(), mx);
    }
  }
  for (int i = 1; i < (1 << n); i++) {
    vector<int> l;
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 1) {
        l.push_back(j);
      }
    }
    int ok = 1;
    for (int j = 1; j < (int)l.size(); j++) {
      ok &= (a[l[j - 1]] < a[l[j]]);
    }
    if (l.size() == mx && ok) {
      tot++;
      for (int j : l) {
        cnt[j]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    if (cnt[i] == 0) {
      cout << 1;
    } else {
      if (cnt[i] != tot) {
        cout << 2;
      } else {
        cout << 3;
      }
    }
  }
  cout << "\n";
}
