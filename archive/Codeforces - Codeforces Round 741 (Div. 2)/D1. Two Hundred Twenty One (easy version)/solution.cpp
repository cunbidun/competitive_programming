#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, Q;
    cin >> N >> Q;
    vector<int> n, p;
    vector<vector<int>> s(2, vector<int>(N + 1));
    for (int i = 1; i <= N; i++) {
      char x;
      cin >> x;
      s[0][i] = s[0][i - 1];
      s[1][i] = s[1][i - 1];
      if (x == '-') {
        n.push_back(i);
      } else {
        p.push_back(i);
        s[i % 2][i] = s[i % 2][i - 1] + 1;
      }
    }
    while (Q--) {
      int l, r;
      cin >> l >> r;
      int x = s[l % 2][r] - s[l % 2][l - 1];
      int x_p = s[1 - l % 2][r] - s[1 - l % 2][l - 1];
      int n_o = (r - l + 1) / 2;
      int n_e = (r - l + 1) / 2;
      if ((r - l + 1) % 2 == 1) {
        n_o++;
      }
      int y = n_o - x;
      int y_p = n_e - x_p;
      int ans = 0;
      if ((x + x_p) % 2) {
        ans++;
      }
      if ((y + y_p) % 2) {
        ans++;
      }
      if (ans == 0 && x != x_p) {
        ans = 2;
      }
      cout << ans << '\n';
    }
  }
}
