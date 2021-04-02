#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, C;
    cin >> N >> C;
    vector<vector<int>> f(N, vector<int>(C + 1, -1));
    function<int(int, int)> solve = [&](int i, int c) {
      if (f[i][c] != -1) {
        return f[i][c];
      }
      if (i == N - 1) {
        return f[i][c] = (c == 0);
      }
      f[i][c] = 0;
      for (int j = i; j < N; j++) {
        if (c >= j - i + 1) {
          f[i][c] |= solve(i + 1, c - (j - i + 1));
        }
      }
      return f[i][c];
    };
    solve(0, C);
    if (f[0][C] == 0) {
      cout << "IMPOSSIBLE\n";
    } else {
      vector<int> p;
      for (int i = 0; i < N - 1; i++) {
        for (int j = i; j < N; j++) {
          if (f[i + 1][C - (j - i + 1)] == 1) {
            p.push_back(j);
            C -= (j - i + 1);
            break;
          }
        }
      }
      vector<int> a(N, 0);
      a[p[(int)p.size() - 1]] = N - 1;
      for (int i = (int)p.size() - 2; i >= 0; i--) {
        reverse(a.begin() + i, a.begin() + p[i] + 1);
        a[p[i]] = i + 1;
      }

      for (int i : a) {
        if (i == 0) {
          cout << N << ' ';
        } else {
          cout << i << ' ';
        }
      }
      cout << '\n';
    }
  }
}
