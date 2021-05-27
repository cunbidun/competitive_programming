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
    vector<int> a(n);
    int mn = 1e9;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      mn = min(mn, a[i]);
    }
    int ans = 0;
    for (int i : a) {
      ans += (i != mn);
    }
    cout << ans << '\n';
  }
}
