#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> f(N + 1, vector<int>(2 * M + 1, 1e9));
  vector<array<int, 2>> a(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i][0] >> a[i][1];
  }
  auto cal = [&](int i, int l, int r) -> array<int, 3> {
    int add = max(0, max(a[i][0] - a[i][1] - l, r - (a[i][0] + a[i][1])));
    if (a[i][0] < l) {
      add = max(r - (a[i][0] + a[i][1]), 0);
    } else if (a[i][0] > r) {
      add = max((a[i][0] - a[i][1]) - l, 0);
    }
    int rl = max(1, a[i][0] - a[i][1] - add);
    int rr = min(N, a[i][0] + a[i][1] + add);
    return {add, rl, rr};
  };
  for (int i = 0; i <= N; i++) {
    f[i][0] = 0;
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= 2 * M; j++) {
      auto [add, rl, rr] = cal(i, min(j, a[i][0]), max(j, a[i][0]));
      f[i][j] = min(f[i - 1][j], f[i - 1][rl - 1] + add);
    }
    for (int j = 2 * M - 1; j >= 1; j--) {
      f[i][j] = min(f[i][j], f[i][j + 1]);
    }
  }
  cout << f[N][M] << '\n';
}
