#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  auto check = [&](int v) {
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      if (a[i] >= v) {
        b[i] = 1;
      } else {
        b[i] = -1;
      }
    }
    for (int i = 1; i < n; i++) {
      b[i] += b[i - 1];
    }
    int mx = b[k - 1];
    int mn = 0;
    for (int i = k; i < n; i++) {
      mn = min(mn, b[i - k]);
      mx = max(mx, b[i] - mn);
    }
    return mx > 0;
  };
  int l = 1;
  int r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << '\n';
}
