#include <bits/stdc++.h>

using namespace std;

const int MX = 100000;
bool f[101][MX + 1];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  vector<int> T(N + 1);
  int s = 0;
  for (int i = 1; i <= N; i++) {
    cin >> T[i];
    s += T[i];
  }
  f[0][0] = 1;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= MX; j++) {
      if (j >= T[i]) {
        f[i][j] |= f[i - 1][j - T[i]];
      }
      f[i][j] |= f[i - 1][j];
    }
  }
  int ans = 1e9;
  for (int i = 1; i <= MX; i++) {
    if (f[N][i] == 1) {
      ans = min(ans, max(i, s - i));
    }
  }
  cout << ans << '\n';
}
