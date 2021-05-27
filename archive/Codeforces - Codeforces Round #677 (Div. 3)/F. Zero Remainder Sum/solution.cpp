#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<int>> v;
  v.push_back(vector<int>(1, 0));
  for (int i = 0; i < n; i++) {
    vector<int> a(m + 1);
    for (int j = 1; j <= m; j++) {
      cin >> a[j];
    }
    vector<vector<vector<int>>> f(m + 1, vector<vector<int>>(k, vector<int>(m / 2 + 1, -1)));
    vector<int> mx(k, -1);
    f[0][0][0] = 0;
    mx[0] = 0;
    for (int j = 1; j <= m; j++) {
      f[j][0][0] = 0;
      for (int r = 0; r <= k - 1; r++) {
        for (int l = 1; l <= m / 2; l++) {
          f[j][r][l] = f[j - 1][r][l];
          int prev = (((r - a[j]) % k) + k) % k;
          if (f[j - 1][prev][l - 1] != -1) {
            f[j][r][l] = max(f[j][r][l], f[j - 1][prev][l - 1] + a[j]);
          }
          mx[r] = max(mx[r], f[j][r][l]);
        }
      }
    }
    v.push_back(mx);
  }

  vector<vector<int>> mx(n + 1, vector<int>(k, -1));
  mx[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int r = 0; r < k; r++) {
      for (int num = 0; num < k; num++) {
        if (v[i][num] != -1) {
          int prev = (((r - num) % k) + k) % k;
          for (int l = 0; l < i; l++) {
            if (mx[l][prev] != -1) {
              mx[i][r] = max(mx[i][r], mx[l][prev] + v[i][num]);
            }
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, mx[i][0]);
  }
  cout << ans << '\n';
}
