#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    int N;
    cin >> N;
    vector<vector<char>> a(N + 1, vector<char>(N + 1));
    vector<int> c(N + 1);
    vector<int> r(N + 1);
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        cin >> a[i][j];
        if (a[i][j] == 'X') {
          r[i]++;
          c[j]++;
        }
        if (a[i][j] == 'O') {
          r[i] = -1e9;
          c[j] = -1e9;
        }
      }
    }
    int mx = 0;
    for (int i = 1; i <= N; i++) {
      mx = max(mx, r[i]);
      mx = max(mx, c[i]);
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
      ans += mx == r[i];
      ans += mx == c[i];
    }
    if (ans == 0) {
      cout << "Impossible\n";
    } else {
      if (mx == N - 1) {
        set<array<int, 2>> s;
        for (int i = 1; i <= N; i++) {
          if (r[i] == mx) {
            for (int j = 1; j <= N; j++) {
              if (a[i][j] == '.') {
                s.insert({i, j});
              }
            }
          }
        }
        for (int j = 1; j <= N; j++) {
          if (c[j] == mx) {
            for (int i = 1; i <= N; i++) {
              if (a[i][j] == '.') {
                s.insert({i, j});
              }
            }
          }
        }
        cout << 1 << ' ' << s.size() << '\n';
      } else {
        cout << N - mx << ' ' << ans << '\n';
      }
    }
  }
}
