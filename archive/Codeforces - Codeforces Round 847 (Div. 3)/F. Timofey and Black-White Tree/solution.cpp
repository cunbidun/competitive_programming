/**
 *  author: cunbidun
 *  created: Monday, 2023-06-19 14:55:47 CDT
 **/
#include <algorithm>
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> c(N);
    for (int i = 0; i < N; i++) {
      cin >> c[i];
      c[i]--;
    }
    vector<vector<int>> a(N);
    for (int i = 0; i < N - 1; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      a[u].push_back(v);
      a[v].push_back(u);
    }
    vector<int> p(N), d(N, N + 1);

    function<void(int, int)> dfs = [&](int u, int l) -> void {
      for (int v : a[u]) {
        if (v != l) {
          p[v] = u;
          dfs(v, u);
        }
      }
    };
    dfs(c[0], c[0]);
    d[c[0]] = 0;
    int ans = 1e9;
    for (int i = 1; i < N; i++) {
      int v = c[i];
      int cnt = 0;
      ans = min(ans, d[v]);
      while (true) {
        v = p[v];
        cnt++;
        ans = min(ans, cnt + d[v]);
        d[v] = min(d[v], cnt);
        if (cnt > ans) {
          break;
        }
        if (v == c[0]) {
          break;
        }
      }
      d[c[i]] = 0;
      cout << ans << ' ';
    }
    cout << '\n';
  }
}
