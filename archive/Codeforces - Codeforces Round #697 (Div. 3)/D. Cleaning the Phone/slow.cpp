#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  cin >> n >> m;
  int ans = 2 * n + 1;
  vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i < (1 << n); i++) {
    int res = 0;
    long long cur = 0;
    for (int j = 0; j < n; j++) {
      if (((i >> j) & 1) == 1) {
        res += b[j];
        cur += a[j];
      }
    }
    if (cur >= m) {
      ans = min(ans, res);
    }
  }
  if (ans != 2 * n + 1) {
    cout << ans << '\n';
  } else {
    cout << "-1\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
