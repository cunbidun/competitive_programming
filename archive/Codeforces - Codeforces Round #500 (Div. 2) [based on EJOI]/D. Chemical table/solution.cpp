#include <bits/stdc++.h>

using namespace std;

struct union_find {
  typedef vector<int> vi;
  vi p, sz, rank;
  int dsu_size;
  union_find(int _n) : p(vi(_n)), sz(vi(_n, 1)), rank(vi(_n)), dsu_size(_n) {
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }
  int find(int i) { return (p[i] == i) ? i : (p[i] = find(p[i])); }
  bool is_same_set(int x, int y) { return find(x) == find(y); }
  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x), y = find(y);
      if (rank[x] > rank[y]) {
        p[y] = x, sz[x] += sz[y];
      } else {
        p[x] = y, sz[y] += sz[x];
        rank[y] += (rank[x] == rank[y]);
      }
    }
  }
  int size(int i) { return sz[find(i)]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, Q;
  cin >> N >> M >> Q;
  vector<vector<int>> a(N + 1);
  for (int i = 0; i < Q; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
  }
  union_find dsu(M + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j < (int)a[i].size(); j++) {
      dsu.merge(a[i][j], a[i][j - 1]);
    }
  }
  int ans = 0;
  for (int i = 1; i <= N; i++) {
    ans += a[i].empty();
  }
  cout << ans + dsu.dsu_size - 2 << '\n';
}
