#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int W, H;
    cin >> W >> H;
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int w, h;
    cin >> w >> h;
    int ans = 1e9;
    if (w + x2 - x1 <= W) {
      ans = min(ans, max(0, w - x1));
      ans = min(ans, max(0, x2 - (W - w)));
    }

    if (h + y2 - y1 <= H) {
      ans = min(ans, max(0, h - y1));
      ans = min(ans, max(0, y2 - (H - h)));
    }
    if (ans == 1e9) {
      cout << -1 << '\n';
      continue;
    }
    cout << ans << '\n';
  }
}
