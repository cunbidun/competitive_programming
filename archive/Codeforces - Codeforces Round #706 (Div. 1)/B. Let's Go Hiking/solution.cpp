#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  vector<int> c(n + 1);
  vector<int> l(n), r(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int d0 = 0;
  int cnt = 1;
  for (int i = 1; i < n; i++) {
    if (a[i - 1] < a[i]) {
      cnt++;
    } else {
      c[cnt]++;
      l[i - 1] = cnt;
      if (cnt > d0) {
        d0 = cnt;
      }
      cnt = 1;
    }
  }
  l[n - 1] = cnt;
  d0 = max(d0, cnt);
  c[cnt]++;
  if (c[d0] > 1) {
    cout << 0 << '\n';
    return 0;
  }
  int d1 = 0;
  c.assign(n + 1, 0);
  cnt = 1;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > a[i + 1]) {
      cnt++;
    } else {
      r[i + 1] = cnt;
      c[cnt]++;
      if (cnt > d1) {
        d1 = cnt;
      }
      cnt = 1;
    }
  }
  c[cnt]++;
  r[0] = cnt;
  d1 = max(d1, cnt);
  if (c[d1] > 1) {
    cout << 0 << '\n';
    return 0;
  }

  for (int i = 1; i < n - 1; i++) {
    if (max(l[i], r[i]) == max(d0, d1)) {
      if (l[i] % 2 == 0 || r[i] != l[i]) {
        cout << 0 << '\n';
        return 0;
      } else {
        cout << 1 << '\n';
        return 0;
      }
    }
  }
  cout << 0 << '\n';
}
