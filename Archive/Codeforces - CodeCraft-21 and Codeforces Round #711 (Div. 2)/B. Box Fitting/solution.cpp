#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    long long W;
    cin >> n >> W;
    vector<long long> a(n);
    vector<long long> b(32);
    long long ans = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    for (long long x : a) {
      int cnt = 0;
      while (x != 1) {
        x /= 2;
        cnt++;
      }
      int p = -1;
      for (int j = cnt; j <= 31; j++) {
        if (b[j] > 0) {
          p = j;
          break;
        }
      }
      if (p == -1) {
        ans++;
        for (int j = 0; j <= 30; j++) {
          if ((W >> j) & 1) {
            b[j]++;
          }
        }
        for (int j = cnt; j <= 31; j++) {
          if (b[j] > 0) {
            p = j;
            break;
          }
        }
      }
      b[p]--;
      b[cnt] += (1L << (p - cnt));
      b[cnt]--;
    }
    cout << ans << '\n';
  }
}
