#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(N + 2, vector<int>(M + 2));
  vector<vector<int>> f(N + 2, vector<int>(M + 2));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }
  for (int j = 1; j <= M; j++) {
    f[1][j] = a[1][j];
  }
  for (int i = 2; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      f[i][j] = max({f[i - 1][j - 1], f[i - 1][j], f[i - 1][j + 1]}) + a[i][j];
    }
  }
  int ans = 0;
  for (int j = 1; j <= M; j++) {
    ans = max(ans, f[N][j]);
  }
  cout << ans << '\n';
}
