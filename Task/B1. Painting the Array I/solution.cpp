#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = n;
  int last = 0;
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] != last) {
      cnt++;
    }
    if (a[i] == a[i - 1]) {
      if (a[i] == last) {
        cout << i << " " << last << " " << cnt << "\n";
        if (cnt < 2) {
          ans--;
        }
      }
      cnt = 0;
      last = a[i];
    }
  }
  cout << ans << "\n";
}
