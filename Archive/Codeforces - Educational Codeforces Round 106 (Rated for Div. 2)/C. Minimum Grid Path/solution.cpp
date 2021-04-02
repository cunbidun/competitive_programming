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
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    long long ans = n * a[0] + n * a[1];
    vector<map<long long, long long>> mp(2, map<long long, long long>());
    map<long long, long long> mp2;
    mp[0][a[0]] = n;
    mp[1][a[1]] = n;
    long long res = ans;
    for (int i = 2; i < n; i++) {
      auto l = *mp[i % 2].rbegin();
      if (a[i] > l.first) {
        mp[i % 2][l.first]--;
        if (mp[i % 2][l.first] == 1) {
          mp[i % 2].erase(l.first);
        }
        res -= l.first;
        res += a[i];
      } else {
        res -= l.first * (l.second - 1);
        res += a[i] * (l.second - 1);
        mp[i % 2].erase(l.first);
        if (l.second - 1 != 1) {
          mp[i % 2][a[i]] = l.second - 1;
        }
      }
      ans = min(ans, res);
    }
    cout << ans << '\n';
  }
}
