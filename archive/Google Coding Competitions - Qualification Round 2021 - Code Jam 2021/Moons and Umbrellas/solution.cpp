#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int X, Y;
    string S;
    cin >> X >> Y >> S;
    vector<vector<int>> f(1000, vector<int>(2, 1e9));
    if (S[0] == 'C') {
      f[0][0] = 0;
    } else if (S[0] == 'J') {
      f[0][1] = 0;
    } else {
      f[0][0] = f[0][1] = 0;
    }
    for (int i = 1; i < S.size(); i++) {
      if (S[i] == 'C') {
        f[i][0] = f[i - 1][0];
        f[i][0] = min(f[i][0], f[i - 1][1] + Y);
      } else if (S[i] == 'J') {
        f[i][1] = f[i - 1][1];
        f[i][1] = min(f[i][1], f[i - 1][0] + X);
      } else {
        f[i][0] = min(f[i - 1][0], f[i - 1][1] + Y);
        f[i][1] = min(f[i - 1][1], f[i - 1][0] + X);
      }
    }
    int n = S.size();
    cout << min(f[n - 1][0], f[n - 1][1]) << '\n';
  }
}
