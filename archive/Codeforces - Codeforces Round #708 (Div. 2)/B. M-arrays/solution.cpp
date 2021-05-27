#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (m == 1) {
      cout << 1 << '\n';
      continue;
    }
    for (int i = 0; i < n; i++) {
      cnt[a[i] % m]++;
    }
    int ans = 0;
    if (cnt[0]) {
      ans = 1;
    }
    if (m % 2 == 0) {
      ans += (cnt[m / 2] != 0);
    }
    for (int i = 1; i <= (m - 1) / 2; i++) {
      if (cnt[i] == 0 || cnt[m - i] == 0) {
        ans += cnt[i];
        ans += cnt[m - i];
      } else {
        ans++;
        if (cnt[i] >= cnt[m - i]) {
          ans += max(0, cnt[i] - cnt[m - i] - 1);
        } else {
          ans += max(0, cnt[m - i] - cnt[i] - 1);
        }
      }
    }
    cout << ans << '\n';
  }
}
