#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 rng(99);
  int T;
  cin >> T;
  vector<pair<int, int>> ans[21][21];
  for (int R = 2; R <= 20; R++) {
    for (int C = 2; C <= 20; C++) {
      vector<vector<int>> g(R * C, vector<int>());
      for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
          for (int k = 0; k < R; k++) {
            for (int l = 0; l < C; l++) {
              if (i != k && j != l && (i + j) != (l + k) && (i - j) != (k - l)) {
                g[i * C + j].push_back(k * C + l);
              }
            }
          }
        }
      }
      for (int i = 0; i < R * C; i++) {
        shuffle(g[i].begin(), g[i].end(), rng);
      }
      vector<int> visited(R * C, 0);
      vector<pair<int, int>> res, cur;
      function<void(int, int)> dfs = [&](int count, int u) {
        if (!res.empty()) {
          return;
        }
        cur.push_back({u / C + 1, u % C + 1});
        visited[u] = 1;
        if (count == R * C - 1) {
          res = cur;
        }
        for (auto v : g[u]) {
          if (visited[v] == 0) {
            dfs(count + 1, v);
          }
        }
        visited[u] = 0;
        cur.pop_back();
      };
      for (int i = 0; i < R * C; i++) {
        dfs(0, i);
      }
      ans[R][C] = res;
    }
  }
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int R, C;
    cin >> R >> C;
    if (ans[R][C].empty()) {
      cout << "IMPOSSIBLE\n";
    } else {
      cout << "POSSIBLE\n";
      for (auto [f, s] : ans[R][C]) {
        cout << f << ' ' << s << '\n';
      }
      cout << '\n';
    }
  }
}