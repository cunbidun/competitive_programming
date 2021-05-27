#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> cnt(1e6 + 1);
  int t = k;
  for (int i = 2; i * i <= k; i++) {
    while (t % i == 0) {
      cnt[i]++;
      t /= i;
    }
  }
  if (t > 1) {
    cnt[t]++;
  }
  vector<pair<int, int>> l;
  for (int i = 0; i <= k; i++) {
    if (cnt[i] > 0) {
      l.push_back({i, cnt[i]});
    }
  }
  for (auto [i, p] : l) {
    int res = 0;
    for (int j : a) {
      t = j;
      int cnt = 0;
      while (t % i == 0) {
        t /= i;
        cnt++;
      }
      res = max(res, cnt);
    }
    if (res < p) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";
}
