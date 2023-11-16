#include <bits/stdc++.h>
#define ios                                                                                                            \
  ios_base::sync_with_stdio(false);                                                                                    \
  cin.tie(0);
#define endl '\n'
#define F first
#define int long long
#define double long double
#define S second
using namespace std;
inline void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<double>> ps(n + 1);
  ps[2] = {0.5, 0};
  for (int i = 4; i <= n; i += 2) {
    ps[i].resize(i, (double)1 / i);
    for (int j = i / 2; j < i - 1; j++) {
      ps[i][j] = (j - 1) * ps[i - 2][j - 2] + (i - j - 1) * ps[i - 2][j - 1];
      ps[i][j] /= i;
    }
    ps[i][i - 1] = 0;
  }
  for (int i = 1; i <= n; i += 2)
    ps[i].resize(i, (double)1 / i);
  vector<double> dp(n);
  dp[n - 1] = 1;
  vector<vector<int>> edge(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    edge[a - 1].push_back(b - 1);
  }
  for (int i = n - 2; i >= 0; i--) {
    vector<double> vals;
    int sz = edge[i].size();
    for (auto j : edge[i])
      vals.push_back(dp[j]);
    sort(vals.rbegin(), vals.rend());
    for (int j = 0; j < sz; j++)
      dp[i] += vals[j] * ps[sz][j];
  }
  cout << dp[0] << endl;
}
signed main() {
  ios int t = 1;
  cin >> t;
  cout.precision(20);
  cout << fixed;
  while (t--)
    solve();
}
