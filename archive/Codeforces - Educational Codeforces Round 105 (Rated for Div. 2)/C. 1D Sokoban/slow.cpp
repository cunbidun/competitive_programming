#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    set<int> b;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      int x;
      cin >> x;
      b.insert(x);
    }
    int ans = 0;
    for (int j : a) {
      if (b.find(j) != b.end()) {
        ans++;
      }
    }
    for (int i = 1; i < 20; i++) {
      if (i == a[0]) {
        a[0]++;
        for (int j = 1; j < n; j++) {
          if (a[j] == a[j - 1]) {
            a[j]++;
          }
        }
      }
      int cnt = 0;
      for (int j : a) {
        if (b.find(j) != b.end()) {
          cnt++;
        }
      }
      ans = max(cnt, ans);
    }
    cout << ans << '\n';
  }
}
