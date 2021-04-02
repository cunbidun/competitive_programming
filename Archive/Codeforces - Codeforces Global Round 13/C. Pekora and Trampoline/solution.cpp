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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = 0;
    vector<long long> sub(n + 1);
    for (int i = 0; i < n; i++) {
      long long s = sub[i];
      long long t = a[i];
      for (int j = min(1LL * n - 1, i + t); j >= max(i + t - s + 1, 1LL * i + 2); j--) {
        sub[j]++;
        sub[i]--;
        a[i]--;
      }
      sub[i + 1] += max(0LL, sub[i] - a[i] + 1);
      a[i] -= sub[i];
      a[i] = max(a[i], 1LL);
      ans += max(0LL, a[i] - 1);
      for (int j = i + 2; j <= min(1LL * n - 1, i + a[i]); j++) {
        sub[j]++;
      }
    }
    cout << ans << '\n';
  }
}
