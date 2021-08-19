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
    string s;
    cin >> s;
    vector<vector<int>> f(N, vector<int>(2, 10000));
    if (s[0] == 'R') {
      f[0][0] = 0;
    } else if (s[0] == 'B') {
      f[0][1] = 0;
    } else {
      f[0][0] = 0;
      f[0][1] = 0;
    }
    for (int i = 1; i < N; i++) {
      if (s[i] == 'R') {
        f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1]);
      } else if (s[i] == 'B') {
        f[i][1] = min(f[i - 1][1] + 1, f[i - 1][0]);
      } else {
        f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1]);
        f[i][1] = min(f[i - 1][1] + 1, f[i - 1][0]);
      }
    }
    string ans = "";
    if (f[N - 1][0] < f[N - 1][1]) {
      ans += 'R';
    } else {
      ans += 'B';
    }
    int cur = N - 2;
    while (cur >= 0) {
      if (s[cur] != '?') {
        ans += s[cur];
      } else {
        char last = ans.back();
        if (last == 'R') {
          if (f[cur][0] + 1 == f[cur + 1][0]) {
            ans += 'R';
          } else {
            ans += 'B';
          }
        } else {
          if (f[cur][1] + 1 == f[cur + 1][1]) {
            ans += 'B';
          } else {
            ans += 'R';
          }
        }
      }
      cur--;
    }
    for (int i = N - 1; i >= 0; i--) {
      cout << ans[i];
    }
    cout << '\n';
  }
}
