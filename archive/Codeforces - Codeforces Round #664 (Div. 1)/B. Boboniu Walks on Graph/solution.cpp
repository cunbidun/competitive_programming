#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<array<int, 2>>> a(n + 1, vector<array<int, 2>>());
  vector<set<array<int, 2>>> p(n + 1, set<array<int, 2>>());
  set<array<int, 4>> x;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back({v, w});
  }
  for (int i = 1; i <= n; i++) {
    sort(a[i].begin(), a[i].end(), [](array<int, 2> a, array<int, 2> b) {
      return a[1] < b[1];
    });
    for (int j = 0; j < (int)a[i].size(); j++) {
      int v = a[i][j][0];
      for (auto [p1, p2] : p[v]) {
        x.insert({(int)a[i].size(), j + 1, p1, p2});
        x.insert({p1, p2, (int)a[i].size(), j + 1});
      }
      p[v].insert({(int)a[i].size(), j + 1});
    }
  }
  int ans = 0;
  vector<int> l;
  function<void(int)> cal = [&](int c) {
    if (c == k + 1) {
      for (int i = 1; i <= k; i++) {
        if (x.find({i, l[i - 1], i, l[i - 1]}) != x.end()) {
          return;
        }
      }
      for (int i = 1; i <= k; i++) {
        for (int j = i + 1; j <= k; j++) {
          if (x.find({i, l[i - 1], j, l[j - 1]}) != x.end()) {
            return;
          }
        }
      }
      ans++;
      return;
    }
    for (int i = 1; i <= c; i++) {
      l.push_back(i);
      cal(c + 1);
      l.pop_back();
    }
  };
  cal(1);
  cout << ans << '\n';
}
