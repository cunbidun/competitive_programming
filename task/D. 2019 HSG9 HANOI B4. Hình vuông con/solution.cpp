#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> a(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> a[i][j];
    }
  }
  auto check = [&](int m) -> int {
    vector<vector<int>> s(N + 1, vector<int>(M + 1));
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (a[i][j] >= m);
      }
    }
    for (int i = K; i <= N; i++) {
      for (int j = K; j <= M; j++) {
        if (s[i][j] - s[i - K][j] - s[i][j - K] + s[i - K][j - K] == K * K) {
          return 1;
        }
      }
    }
    return 0;
  };
  int l = 0, r = 1e9;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (check(m)) {
      l = m;
    } else {
      r = m - 1;
    }
  }
  cout << l << '\n';
}
