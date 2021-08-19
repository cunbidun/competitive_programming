#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<vector<int>> a(N + 1, vector<int>(5));
    for (int i = 1; i <= N; i++) {
      for (int j = 0; j < 5; j++) {
        cin >> a[i][j];
      }
    }
    int cur = 1;
    for (int i = 2; i <= N; i++) {
      int cnt = 0;
      for (int j = 0; j < 5; j++) {
        cnt += a[cur][j] < a[i][j];
      }
      if (cnt < 3) {
        cur = i;
      }
    }
    int f = 0;
    for (int i = 1; i <= N; i++) {
      if (i != cur) {
        int cnt = 0;
        for (int j = 0; j < 5; j++) {
          cnt += a[cur][j] < a[i][j];
        }
        f |= (cnt < 3);
      }
    }
    if (f) {
      cout << -1 << '\n';
    } else {
      cout << cur << '\n';
    }
  }
}
