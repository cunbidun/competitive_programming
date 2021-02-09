#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int &p : a) {
      cin >> p;
    }
    for (int &p : b) {
      cin >> p;
    }
    for (int &p : c) {
      cin >> p;
    }
    long long ans = 0;
    long long last = 0;
    for (int i = 1; i < n; i++) {
      int mn = min(b[i], c[i]);
      int mx = max(b[i], c[i]);
      long long cur = 1LL * (a[i] + (mx - mn + 1));
      if (mn != mx && i != 1) {
        cur = max(cur, last - a[i - 1] + mn + a[i - 1] - mx + 1 + a[i]);
      }
      last = cur;
      ans = max(ans, cur);
    }
    cout << ans << "\n";
  }
}
