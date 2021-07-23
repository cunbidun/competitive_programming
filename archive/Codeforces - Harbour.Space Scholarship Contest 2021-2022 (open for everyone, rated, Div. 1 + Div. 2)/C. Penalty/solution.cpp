#include <bits/stdc++.h>

using namespace std;

int cnto(int i, int c) {
  int cnt = 0;
  for (int j = i + 1; j <= 10; j++) {
    cnt += (j % 2 == c);
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(11);
    vector<int> l;
    for (int i = 1; i <= 10; i++) {
      char c;
      cin >> c;
      if (c == '1') {
        a[i] = 1;
      } else if (c == '0') {
        a[i] = 0;
      } else {
        a[i] = -1;
        l.push_back(i);
      }
    }
    int n = l.size();
    int ans = 10;
    for (int mask = 0; mask < (1 << n); mask++) {
      for (int i = 0; i < n; i++) {
        if ((mask >> i) & 1) {
          a[l[i]] = 1;
        } else {
          a[l[i]] = 0;
        }
      }
      vector<int> cnt(2);
      for (int i = 1; i <= 10; i++) {
        cnt[i % 2] += a[i];
        if (cnt[0] + cnto(i, 0) < cnt[1] || cnt[1] + cnto(i, 1) < cnt[0]) {
          ans = min(ans, i);
          break;
        }
      }
    }
    cout << ans << '\n';
  }
}
