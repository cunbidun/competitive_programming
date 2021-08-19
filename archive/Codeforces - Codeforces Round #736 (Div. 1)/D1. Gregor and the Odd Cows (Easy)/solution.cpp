#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<vector<int>> cnt(4, vector<int>(4));
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    cnt[x % 4][y % 4]++;
  }
  vector<array<int, 2>> l;
  for (int i = 0; i < 4; i += 2) {
    for (int j = 0; j < 4; j += 2) {
      l.push_back({i, j});
    }
  }
  int n = (int)l.size();
  auto p = [](array<int, 2> a, array<int, 2> b) -> int {
    return __gcd(abs(a[0] - b[0]), abs(a[1] - b[1]));
  };
  auto check = [&](int i, int j, int k) {
    return (p(l[i], l[j]) + p(l[j], l[k]) + p(l[k], l[i])) % 4 == 0;
  };
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      for (int k = j; k < n; k++) {
        if (check(i, j, k)) {
          long long res = 0;
          if (i == j && j == k) {
            int tmp = cnt[l[i][0]][l[i][1]];
            res = 1LL * tmp * (tmp - 1) * (tmp - 2) / 6;
          } else {
            if (i == j) {
              int tmp = cnt[l[i][0]][l[i][1]];
              res = 1LL * tmp * (tmp - 1) / 2 * cnt[l[k][0]][l[k][1]];
            } else if (i == k) {
              int tmp = cnt[l[i][0]][l[i][1]];
              res = 1LL * tmp * (tmp - 1) / 2 * cnt[l[j][0]][l[j][1]];
            } else if (j == k) {
              int tmp = cnt[l[j][0]][l[j][1]];
              res = 1LL * tmp * (tmp - 1) / 2 * cnt[l[i][0]][l[i][1]];
            } else {
              res = cnt[l[i][0]][l[i][1]] *
                    cnt[l[j][0]][l[j][1]] *
                    cnt[l[k][0]][l[k][1]];
            }
          }
          ans += res;
        }
      }
    }
  }
  cout << ans << '\n';
}
