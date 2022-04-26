#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  long long INF = 1e18;
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, P;
    cin >> N >> P;
    vector<array<long long, 2>> c(N);
    for (int i = 0; i < N; i++) {
      int mx = 0, mn = 2e9;
      for (int j = 0; j < P; j++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
      }
      c[i] = {mn, mx};
    }
    vector<array<long long, 2>> f(N, {INF, INF});
    f[0][0] = c[0][1];
    f[0][1] = c[0][1] + c[0][1] - c[0][0];
    for (int i = 1; i < N; i++) {
      f[i][0] =
          min(f[i - 1][0] + abs(c[i][0] - c[i - 1][1]), f[i - 1][1] + abs(c[i][0] - c[i - 1][0])) + c[i][1] - c[i][0];

      f[i][1] =
          min(f[i - 1][0] + abs(c[i][1] - c[i - 1][1]), f[i - 1][1] + abs(c[i][1] - c[i - 1][0])) + c[i][1] - c[i][0];
    }
    cout << min(f[N - 1][0], f[N - 1][1]) << '\n';
  }
}
