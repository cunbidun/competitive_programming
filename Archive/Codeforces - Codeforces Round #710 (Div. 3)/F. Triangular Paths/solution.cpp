#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i].first;
    }
    for (int i = 0; i < n; i++) {
      cin >> p[i].second;
    }
    sort(p.begin(), p.end());
    function<int(int, int, int, int)> dis = [&dis](int x1, int y1, int x2, int y2) -> int {
      if (x1 == x2 && y1 == y2) {
        return 0;
      }
      if ((x1 + y1) % 2 == 0) {
        if (x1 - x2 == y1 - y2) {
          return x2 - x1;
        }
        return dis(x1 + 1, y1, x2, y2);
      }
      int d = x2 - (x1 + y2 - y1);
      if (d % 2 == 0) {
        return d / 2;
      }
      return (d + 1) / 2;
    };
    int ans = 0;
    int x = 1, y = 1;
    for (auto [f, s] : p) {
      ans += dis(x, y, f, s);
      // cout << ans << ' ';
      x = f;
      y = s;
    }
    cout << ans << '\n';
  }
}
