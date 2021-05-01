#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<long long> a(n), b(n);
  vector<vector<long long>> g(n, vector<long long>(n));

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    g[i][i] = a[i] * b[i];
  }
  for (int i = 0; i < n - 1; i++) {
    g[i][i + 1] = a[i] * b[i + 1] + a[i + 1] * b[i];
  }
  for (int l = 2; l < n; l++) {
    for (int i = 0; i < n; i++) {
      if (i + l < n) {
        g[i][i + l] = g[i + 1][i + l - 1] + a[i] * b[i + l] + b[i] * a[i + l];
      }
    }
  }

  vector<vector<long long>> f(n, vector<long long>(2));
  f[0][0] = a[0] * b[0];
  f[0][1] = a[0] * b[0];
  for (int i = 1; i < n; i++) {
    f[i][0] = max(f[i - 1][0], f[i - 1][0] + a[i] * b[i]);
    f[i][1] = max(g[0][i], f[i - 1][1] + a[i] * b[i]);
    for (int j = 0; j < i; j++) {
      f[i][1] = max(f[i][1], f[j][0] + g[j + 1][i]);
    }
  }
  cout << max(f[n - 1][0], f[n - 1][1]) << '\n';
}
