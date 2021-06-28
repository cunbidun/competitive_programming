#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N = 500000;
  int R = sqrt(N);
  vector<int> a(N + 1);
  vector<vector<int>> sum(1000, vector<int>(1000));
  int Q;
  cin >> Q;
  while (Q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      a[x] += y;
      for (int i = 1; i <= R; i++) {
        sum[x % i][i] += y;
      }
    } else {
      int ans = 0;
      if (x > R) {
        for (int i = y; i <= N; i += x) {
          ans += a[i];
        }
      } else {
        ans = sum[y][x];
      }
      cout << ans << '\n';
    }
  }
}
