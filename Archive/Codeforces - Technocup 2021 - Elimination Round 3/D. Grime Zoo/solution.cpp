#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  long long x, y;
  cin >> s;
  cin >> x >> y;

  int n = (int)s.size();
  s = ' ' + s + ' ';
  if (x > y) {
    swap(x, y);
    for (int i = 1; i <= n; i++) {
      if (s[i] == '1') {
        s[i] = '0';
      } else if (s[i] == '0') {
        s[i] = '1';
      }
    }
  }
  vector<vector<int>> cnt(n + 2, vector<int>(2));
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    cnt[i][0] = cnt[i - 1][0];
    cnt[i][1] = cnt[i - 1][1];
    if (s[i] == '?' || s[i] == '0') {
      ans += y * cnt[i][1];
      cnt[i][0]++;
    } else {
      ans += x * cnt[i][0];
      cnt[i][1]++;
    }
  }

  long long cur = ans;
  for (int i = n; i >= 1; i--) {
    cnt[i][0] = cnt[i + 1][0];
    cnt[i][1] = cnt[i + 1][1];
    if (s[i] == '1') {
      cnt[i][1]++;
    } else {
      cnt[i][0]++;
    }
    if (s[i] == '?') {
      cnt[i][0]--;
      cnt[i][1]++;
      cur -= x * cnt[i + 1][1] + y * cnt[i - 1][1];
      cur += y * cnt[i + 1][0] + x * cnt[i - 1][0];
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
}
