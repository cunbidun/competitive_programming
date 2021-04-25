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

  function<int(int, int)> solve = [&](int l, int r) {
    if (l > r) {
      return 0;
    }
    int mn = 2e9;
    int p = -1;
    for (int i = l; i <= r; i++) {
      if (mn > a[i]) {
        mn = a[i];
        p = i;
      }
    }
    for (int i = l; i <= r; i++) {
      a[i] -= mn;
    }
    return min(r - l + 1, solve(l, p - 1) + solve(p + 1, r)+ mn);
  };
  cout << solve(0, n - 1) << '\n';
}
