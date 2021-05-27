#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  if (n < m) {
    cout << 0 << '\n';
    return 0;
  }
  vector<int> a(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> b[i];
  }
  map<int, int> mp;
  for (int i = 1; i <= n; i++) {
    mp[a[i]] = i;
  }
  int cur = 1;
  int ans = 1;
  for (int i = 1; i <= m; i++) {
    int p = mp[b[i]];
    if (p < cur) {
      cout << 0 << '\n';
      return 0;
    }
    int e = 0;
    int mn = 1e9 + 7;
    for (int j = p; j >= cur; j--) {
      if (a[j] < b[i]) {
        if (e == 0) {
          e = j;
        }
      }
      mn = min(mn, a[j]);
    }
    if (mn < b[i - 1]) {
      cout << 0 << '\n';
      return 0;
    }
    if (e != 0 && i == 1) {
      cout << 0 << '\n';
      return 0;
    }
    if (i != 1) {
      ans = (1LL * ans * (p - e)) % 998244353;
    }
    cur = p;
  }
  for (int i = cur; i <= n; i++) {
    if (a[i] < b[m]) {
      cout << 0 << '\n';
      return 0;
    }
  }
  cout << ans << '\n';
}
