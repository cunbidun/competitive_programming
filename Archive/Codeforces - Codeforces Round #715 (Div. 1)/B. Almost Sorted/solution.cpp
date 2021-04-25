#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<long long> f(1e5 + 5, 0);
  f[0] = 1;
  f[1] = 1;
  for (int i = 2; i <= 1e5 + 2; i++) {
    f[i] = 2 * f[i - 1];
    if (f[i] > 1e18) {
      f[i] = 1e18 + 1;
    }
  }
  int t;
  cin >> t;
  while (t--) {
    long long n, k;
    cin >> n >> k;
    if (f[n] < k) {
      cout << -1 << '\n';
      continue;
    }
    int cur = 0;
    vector<int> ans;
    while (cur < n) {
      int p = -1;
      int l = n - cur;
      for (int j = 1; j <= l; j++) {
        if (f[l - j] >= k) {
          p = j;
          break;
        } else {
          k -= f[l - j];
        }
      }
      for (int j = cur + p; j > cur; j--) {
        ans.push_back(j);
      }
      cur += p;
    }
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
