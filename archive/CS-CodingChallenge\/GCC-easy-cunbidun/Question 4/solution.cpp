#include <bits/stdc++.h>
using namespace std;

#define int long long
main() {
  int n, m;

  cin >> n >> m;
  string p[n], x[n], y[n];

  for (int i = 0; i < n; i++) {
    cin >> p[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> x[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> y[i];
  }

  int pi[n], xi[n], yi[n];
  int val[n];
  int ans = 0;
  for (int i = 0; i < n; i++) {
    p[i].erase(remove(p[i].begin(), p[i].end(), '.'), p[i].end());
    x[i].erase(remove(x[i].begin(), x[i].end(), '.'), x[i].end());
    y[i].erase(remove(y[i].begin(), y[i].end(), '.'), y[i].end());

    pi[i] = stoi(p[i]);
    xi[i] = stoi(x[i]);
    yi[i] = stoi(y[i]);
    val[i] = pi[i] * xi[i] - (100 - pi[i]) * yi[i];
  }
  sort(val, val + n, greater<int>());
  for (int i = 0; i < min(n, m); i++) {
    if (val[i] < 0) {
      break;
    }
    ans += val[i];
  }

  cout << fixed << setprecision(2);
  // cout << ans << "\n";
  cout << ans / 10000.0 << "\n";

  return 0;
}
