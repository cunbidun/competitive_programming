#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  vector<int> l;
  for (int i = 0; i < n; i++) {
    cin >> a[i].first >> a[i].second;
    l.push_back(i);
  }

  int ans = 1e9;

  do {
    if (l[0] != 0) {
      continue;
    }
    int res = 0;
    for (int i = 1; i < n; i++) {
      res += max(a[l[i - 1]].second, a[l[i]].first - a[l[i - 1]].first);
    }
    res += max(a[l[n - 1]].second, a[l[0]].first - a[l[n - 1]].first);
    ans = min(ans, res);
   // if (res == 10) {
    //   for (int i : l) {
    //     cout << i << ' ';
    //   }
    //   cout << '\n';
    // }
  } while (next_permutation(l.begin(), l.end()));
  cout << ans << '\n';
}
