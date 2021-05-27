#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int U;
    cin >> U;
    map<char, long long> cnt;
    for (int i = 0; i < 10000; i++) {
      string x, y;
      cin >> x >> y;
      reverse(y.begin(), y.end());
      long long p = 1;
      for (int j = 0; j < y.size(); j++) {
        cnt[y[j]] += p;
        p *= 10;
      }
    }
    vector<pair<long long, char>> l;
    for (auto p : cnt) {
      l.push_back({p.second, p.first});
    }
    sort(l.begin(), l.end());
    string ans = "";
    for (int i = 9; i >= 1; i--) {
      ans += l[i].second;
    }
    ans = l[0].second + ans;
    cout << ans << '\n';
  }
}
