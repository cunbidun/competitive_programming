#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  vector<int> a(n), child(n);
  vector<array<int, 2>> p(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<vector<array<int, 2>>> T(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w, u--, v--;
    T[u].push_back({v, w}), T[v].push_back({u, w});
  }
  function<void(int u, int l)> dfs = [&](int u, int l) {
    for (auto [v, w] : T[u]) {
      if (v != l) {
        p[v] = {u, v};
        dfs(v, u);
      }
    }
  };
  dfs(0, 0);
  function<int(int u, int l, long long c)> cal = [&](int u, int l, long long c) {
    int cnt = 1;
    vector<int> cl;
    for (auto [v, w] : T[u]) {
      if (v != l && w <= c + a[u]) {
        int child_size = cal(v, u, c + a[u] - w);
        cnt += child_size;
        cl.push_back(child_size);
      }
    }
    return cnt;
  };
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    ans += cal(i, i, 0) - 1;
  }
  cout << ans << '\n';
}
