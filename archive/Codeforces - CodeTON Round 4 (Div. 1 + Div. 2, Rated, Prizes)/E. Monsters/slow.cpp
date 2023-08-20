/**
 *  author: cunbidun
 *  created: Monday, 2023-06-12 23:16:16 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <set>
#include <vector>

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
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    vector<int> done(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        done[i] = 1;
      }
    }
    vector<array<int, 2>> edge;
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      edge.push_back({u, v});
    }
    union_find dsu(N);
    for (int i = 0; i < 2 * M; i++) {
      for (auto [u, v] : edge) {
        if ((done[v] && a[u] <= dsu.size(v)) || (done[u] && a[v] <= dsu.size(u))) {
          done[u] = 1;
          done[v] = 1;
          dsu.merge(u, v);
        }
      }
    }
    if (dsu.dsu_size == 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
