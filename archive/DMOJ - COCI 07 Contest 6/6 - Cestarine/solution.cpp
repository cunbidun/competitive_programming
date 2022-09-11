#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  const long long INF = 1e18;
  int N;
  cin >> N;
  vector<int> a(N), b(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i] >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<array<long long, 3>> f(N, {INF, INF, INF});
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      if (j == 0 && a[i] == b[i]) {
        continue;
      }
      if (i < j) {
        continue;
      }
      if (j == 0) {
        f[i][j] = abs(a[i] - b[i]);
        if (i != 0) {
          f[i][j] += min({f[i - 1][0], f[i - 1][1], f[i - 1][2]});
        }
      }
      if (j == 1) {
        f[i][j] = abs(a[i] - b[i - 1]) + abs(a[i - 1] - b[i]);
        if (i - 1 != 0) {
          f[i][j] += min({f[i - 2][0], f[i - 2][1], f[i - 2][2]});
        }
      }
      if (j == 2) {
        f[i][j] = min(abs(a[i] - b[i - 1]) + abs(a[i - 1] - b[i - 2]) + abs(a[i - 2] - b[i]),
                      abs(a[i] - b[i - 2]) + abs(a[i - 1] - b[i]) + abs(a[i - 2] - b[i - 1]));
        if (i - 2 != 0) {
          f[i][j] += min({f[i - 3][0], f[i - 3][1], f[i - 3][2]});
        }
      }
    }
  }
  cout << min({f[N - 1][0], f[N - 1][1], f[N - 1][2]}) << '\n';
}
