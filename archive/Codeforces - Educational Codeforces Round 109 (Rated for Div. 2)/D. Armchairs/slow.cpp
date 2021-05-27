#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<int>> f(n, vector<int>(n, -1));
  function<int(int, int)> cal = [&](int l, int r) {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (r == l) {
      if (a[l] == 1) {
        return f[l][r] = 1e9;
      }
      return f[l][r] = 0;
    }
    if (r - l + 1 == 2) {
      if (a[l] != a[r]) {
        return f[l][r] = 1;
      } else if (a[l] == 1) {
        return f[l][r] = 1e9;
      } else {
        return f[l][r] = 0;
      }
    }
    int res = 1e9;
    for (int i = l; i < r; i++) {
      res = min(res, cal(l, i) + cal(i + 1, r));
    }
    if (a[l] != a[r]) {
      res = min(res, r - l + cal(l + 1, r - 1));
    }
    return f[l][r] = res;
  };
  cout << cal(0, n - 1) << '\n';
}
