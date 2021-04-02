#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, r;
  cin >> k >> r;
  vector<int> a(k);
  for (int i = 0; i < k; i++) {
    cin >> a[i];
  }
  long long ans = 0;
  for (int i = 1; i <= r; i++) {
    int mn = 1000000;
    for (int j = 0; j < k; j++) {
      int x;
      cin >> x;
      if (x != 0) {
        mn = min(mn, a[j] / x);
      }
    }
    int p;
    cin >> p;
    ans = max(ans, 1LL * p * mn);
  }
  cout << ans << '\n';
}
