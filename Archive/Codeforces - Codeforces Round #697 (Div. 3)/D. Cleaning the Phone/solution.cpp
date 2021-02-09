#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n, m;
  long long s1 = 0, s2 = 0, s = 0;
  cin >> n >> m;
  int ans = 2 * n;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s += a[i];
  }

  vector<int> l1, l2;
  for (int i = 1; i <= n; i++) {
    int b;
    cin >> b;
    if (b == 1) {
      l1.push_back(a[i]);
    } else {
      l2.push_back(a[i]);
    }
  }
  if (s < m) {
    cout << -1 << "\n";
    return;
  }

  sort(l1.begin(), l1.end());
  sort(l2.begin(), l2.end());
  reverse(l1.begin(), l1.end());
  reverse(l2.begin(), l2.end());

  for (int i = 0; i < (int)l2.size(); i++) {
    s2 += l2[i];
    if (s2 >= m) {
      ans = min(ans, (i + 1) * 2);
    }
  }
  int p = (int)l2.size() - 1;
  int cur = 2 * (p + 1);
  for (int i = 0; i < (int)l1.size(); i++) {
    s1 += l1[i];
    cur++;
    while (p >= 0 && s2 - l2[p] + s1 >= m) {
      s2 -= l2[p];
      p--;
      cur -= 2;
    }
    if (s1 + s2 >= m) {
      ans = min(ans, cur);
    }
  }
  cout << ans << '\n';
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
