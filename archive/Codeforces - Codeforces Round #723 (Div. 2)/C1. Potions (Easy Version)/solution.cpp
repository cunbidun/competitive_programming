#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> a(N + 1);
  vector<vector<long long>> f(N + 1, vector<long long>(N + 1, -1e18));
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }
  f[0][0] = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 0; j <= i; j++) {
      if (i > j && f[i - 1][j] >= 0) {
        f[i][j] = f[i - 1][j];
      }
      if (j > 0 && f[i - 1][j - 1] >= 0 && f[i - 1][j - 1] + a[i] >= 0) {
        f[i][j] = max(f[i][j], f[i - 1][j - 1] + a[i]);
      }
    }
  }
  for (int i = N; i >= 0; i--) {
    if (f[N][i] >= 0) {
      cout << i << '\n';
      return 0;
    }
  }
}
