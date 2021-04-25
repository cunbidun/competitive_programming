#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  vector<vector<int>> v(1e5 + 5);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    int cur = l;
    int ans = 1;
    for (int i = l; i <= r; i++) {
      int f = 0;
      for (int j = cur; j < i; j++) {
        f |= __gcd(a[i], a[j]) != 1;
      }
      if (f) {
        ans++;
        cur = i;
      }
    }
    cout << ans << '\n';
  }
}
