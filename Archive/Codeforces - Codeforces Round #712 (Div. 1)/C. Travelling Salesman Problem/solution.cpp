#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    ans += a[i].second;
  }
  sort(a.begin(), a.end());
  int cur = a[0].first + a[0].second;
  for (int i = 1; i < n; i++) {
    if (a[i].first > cur) {
      ans += a[i].first - cur;
    }
    cur = max(cur, a[i].first + a[i].second);
  }
  cout << ans << '\n';
}
