#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, P;
  cin >> N >> P;
  vector<vector<array<int, 2>>> f(N + 1, vector<array<int, 2>>(3 * N, {0, 0}));
  f[1][1][0] = 0;
  f[1][1][1] = 1;
  for (int i = 1; i < N; i++) {
    for (int j = 2 * i - 1; j <= 3 * i - 2; j++) {
      for (int k = 2; k <= N; k++) {
        f[k][j + 2 * (k - i - 1)][0] += f[i][j][1];
        f[k][j + 2 * (k - i - 1)][1] += 2 * f[i][j][1];
        f[k][j + 2 * (k - i - 1) + 1][1] += f[i][j][1];
      }
    }
  }
  for (int i = 3 * N - 3; i >= 2 * N - 1; i--) {
    cout << f[N][i][0] + f[N][i][1] << ' ';
  }
  cout << 1 << '\n';
  cout << 1 << '\n';
}
