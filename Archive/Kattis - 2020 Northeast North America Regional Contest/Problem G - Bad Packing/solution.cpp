#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, c;
  cin >> n >> c;
  vector<int> a(n + 1);
  int s = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (c >= s) {
    cout << s << '\n';
    return 0;
  }
  vector<vector<int>> f(n + 1, vector<int>(c + 1, -1));
  f[0][0] = 0;
  f[1][0] = a[1];
  for (int i = 2; i <= n; i++) {
    f[i][0] = min(f[i - 1][0], a[i]);
  }
  for (int i = 1; i <= n; i++) {
    for (int w = 1; w <= c; w++) {
      if (f[i - 1][w] == 0) {
        f[i][w] = a[i];
      } else if (f[i - 1][w] != -1) {
        f[i][w] = min(f[i - 1][w], a[i]);
      }
      if (w >= a[i]) {
        f[i][w] = max(f[i - 1][w - a[i]], f[i][w]);
      }
    }
  }
  for (int w = 0; w <= c; w++) {
    if (f[n][w] + w > c) {
      cout << w << '\n';
      break;
    }
  }
}
