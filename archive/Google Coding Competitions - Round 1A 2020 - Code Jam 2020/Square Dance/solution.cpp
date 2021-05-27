#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, C;
    cin >> R >> C;
    vector<vector<int>> A(R, vector<int>(C));
    vector<vector<int>> u(R, vector<int>(C));
    vector<vector<int>> d(R, vector<int>(C));
    vector<vector<int>> l(R, vector<int>(C));
    vector<vector<int>> r(R, vector<int>(C));
    vector<vector<int>> visited(R, vector<int>(C));
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cin >> A[i][j];
        u[i][j] = i - 1;
        d[i][j] = i + 1;
        l[i][j] = j - 1;
        r[i][j] = j + 1;
      }
    }
    auto weak = [&](int i, int j) {
      if (i == -1 || i == R || j == -1 || j == C || visited[i][j]) {
        return false;
      }
      int cnt = 0;
      int acc = 0;
      if (u[i][j] != -1) {
        cnt++;
        acc += A[u[i][j]][j];
      }
      if (d[i][j] != R) {
        cnt++;
        acc += A[d[i][j]][j];
      }
      if (l[i][j] != -1) {
        cnt++;
        acc += A[i][l[i][j]];
      }
      if (r[i][j] != C) {
        cnt++;
        acc += A[i][r[i][j]];
      }
      if (A[i][j] * cnt < acc) {
        visited[i][j] = 1;
        return true;
      } else {
        return false;
      }
    };
    auto remove = [&](int i, int j) {
      if (u[i][j] != -1) {
        d[u[i][j]][j] = d[i][j];
      }
      if (d[i][j] != R) {
        u[d[i][j]][j] = u[i][j];
      }
      if (l[i][j] != -1) {
        r[i][l[i][j]] = r[i][j];
      }
      if (r[i][j] != C) {
        l[i][r[i][j]] = l[i][j];
      }
    };
    vector<pair<int, int>> w;
    long long cur = 0;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        cur += A[i][j];
        if (weak(i, j)) {
          w.push_back({i, j});
        }
      }
    }
    long long ans = cur;
    while (!w.empty()) {
      for (auto [i, j] : w) {
        cur -= A[i][j];
        remove(i, j);
      }
      vector<pair<int, int>> new_w;
      for (auto [i, j] : w) {
        if (weak(u[i][j], j)) {
          new_w.push_back({u[i][j], j});
        }
        if (weak(d[i][j], j)) {
          new_w.push_back({d[i][j], j});
        }
        if (weak(i, l[i][j])) {
          new_w.push_back({i, l[i][j]});
        }
        if (weak(i, r[i][j])) {
          new_w.push_back({i, r[i][j]});
        }
      }
      swap(w, new_w);
      ans += cur;
    }
    cout << ans << '\n';
  }
}
