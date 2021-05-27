#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long ans = 0;
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  ans += a[0];
  for (int i = 1; i < n; i++) {
    if (a[i] != a[i - 1] + 1) {
      ans += a[i];
    }
  }
  cout << ans << '\n';
}
