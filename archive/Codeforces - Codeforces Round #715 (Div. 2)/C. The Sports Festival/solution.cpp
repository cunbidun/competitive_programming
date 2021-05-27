#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  vector<vector<long long>> f(n, vector<long long>(n, -1));
  function<long long(int, int)> solve = [&](int l, int r) {
    if (f[l][r] != -1) {
      return f[l][r];
    }
    if (l == r) {
      return f[l][r] = 0;
    }
    return f[l][r] = min(solve(l + 1, r), solve(l, r - 1)) + a[r] - a[l];
  };
  cout << solve(0, n - 1) << '\n';
}
