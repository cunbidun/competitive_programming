#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int p[] = {(int)1e9 + 7, (int)1e9 + 9};
    int cur = 0;
    vector<array<int, 4>> ans;
    for (int i = 1; i < n; i++) {
      if (__gcd(a[i], a[i - 1]) != 1) {
        if (a[i] < a[i - 1]) {
          a[i - 1] = p[cur];
          ans.push_back({i + 1, i, a[i], p[cur]});
          cur = 1 - cur;
        } else {
          a[i] = p[cur];
          ans.push_back({i + 1, i, p[cur], a[i - 1]});
          cur = 1 - cur;
        }
      }
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
      cout << p[0] << ' ' << p[1] << ' ' << p[2] << ' ' << p[3] << '\n';
    }
  }
}
