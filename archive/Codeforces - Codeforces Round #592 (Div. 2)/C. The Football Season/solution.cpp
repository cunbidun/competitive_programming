#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t N, P, D, W;
  cin >> N >> P >> W >> D;
  int64_t g = W - D;
  int64_t z = -1, x;
  int64_t mn = max(N - P / D, (int64_t)0);
  for (int64_t i = mn; i <= mn + 2 * g; i++) {
    int64_t sub = P - D * (N - i);
    if (sub >= 0 && sub % g == 0) {
      z = i;
      x = sub / g;
      break;
    }
  }
  if (z == -1 || x > N || N - x - z < 0) {
    cout << -1 << '\n';
    return 0;
  }
  cout << x << ' ' << N - x - z << ' ' << z << '\n';
}
