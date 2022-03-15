#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M, R, C;
    cin >> N >> M >> R >> C;
    vector<string> a(N);
    int b = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        b |= a[i][j] == 'B';
      }
    }
    if (b == 0) {
      cout << -1 << '\n';
      continue;
    }
    if (a[R - 1][C - 1] == 'B') {
      cout << 0 << '\n';
      continue;
    }
    int ok = 0;
    for (int i = 0; i < M; i++) {
      ok |= a[R - 1][i] == 'B';
    }
    for (int i = 0; i < N; i++) {
      ok |= a[i][C - 1] == 'B';
    }
    cout << (ok ? 1 : 2) << '\n';
  }
}
