#include <bits/stdc++.h>

using namespace std;

int main() {
  const int N = 500;
  vector<vector<int>> a(500, vector<int>());
  for (int i = 1; i <= 200; i++) {
    for (int j = 1; j <= i; j++) {
      if ((i & j) == j) {
        a[i].push_back(j+ i);
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    vector<int> visited(500, 0);
    function<void(int)> dfs = [&](int u) {
      visited[u] = 1;
      for (int v : a[u]) {
        if (!visited[v]) {
          dfs(v);
        }
      }
    };
    dfs(x);
    if (visited[y] == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
