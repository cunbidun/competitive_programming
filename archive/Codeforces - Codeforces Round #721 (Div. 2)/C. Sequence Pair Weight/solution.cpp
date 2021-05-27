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
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      mp[x].push_back(i);
    }
    long long ans = 0;
    for (auto [k, v] : mp) {
      long long s = 0;
      for (int i : v) {
        ans += s * (n - i);
        s += i + 1;
      }
    }
    cout << ans << '\n';
  }
}
