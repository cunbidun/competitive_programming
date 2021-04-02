#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, k;
  cin >> n >> k;
  vector<vector<int>> a(k, vector<int>(k, 1));
  for (int _i = 0; _i < n; _i++) {
    string s;
    cin >> s;
    vector<int> pos(k);
    for (int i = 0; i < k; i++) {
      pos[s[i] - 'A'] = i;
    }
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        if (pos[i] >= pos[j]) {
          a[i][j] = 0;
        }
      }
    }
  }

  vector<vector<int>> graph(k, vector<int>());
  vector<int> l;
  vector<int> visited(k);
  function<void(int)> topological_sort = [&](int u) {
    visited[u] = 1;
    for (int v : graph[u])
      if (!visited[v]) {
        topological_sort(v);
      }
    l.push_back(u);
  };
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < k; j++) {
      if (a[i][j] == 1) {
        graph[i].push_back(j);
      }
    }
  }
  for (int i = 0; i < k; i++) {
    if (!visited[i]) {
      topological_sort(i);
    }
  }
  vector<int> f(k);
  for (int i : l) {
    int mx = 0;
    for (int j : graph[i]) {
      mx = max(mx, f[j]);
    }
    f[i] = mx + 1;
  }
  cout << *max_element(f.begin(), f.end()) << '\n';
}
