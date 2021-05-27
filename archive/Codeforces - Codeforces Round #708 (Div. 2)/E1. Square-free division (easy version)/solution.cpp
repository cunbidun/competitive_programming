#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      int c = 1;
      for (int j = 2; j * j <= x; j++) {
        int cnt = 0;
        while (x % j == 0) {
          x /= j;
          cnt++;
        }
        if (cnt % 2 == 1) {
          c *= j;
        }
      }
      if (x) {
        c *= x;
      }
      a.push_back(c);
    }
    set<int> s;
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (s.find(a[i]) != s.end()) {
        s.clear();
        ans++;
      }
      s.insert(a[i]);
    }
    cout << ans << '\n';
  }
}
