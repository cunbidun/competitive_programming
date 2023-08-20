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
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    union_find dsu(N);
    vector<vector<int>> g(N);
    for (int i = 0; i < M; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    vector<int> zero;
    for (int i = 0; i < N; i++) {
      if (a[i] == 0) {
        zero.push_back(i);
      }
    }
    vector<int> done(N);

    for (auto start : zero) {
      priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
      set<int> visited;
      done[start] = 1;
      visited.insert(start);
      for (auto i : g[start]) {
        visited.insert(i);
        pq.push({a[i], i});
      }

      while (!pq.empty()) {
        auto [l, u] = pq.top();
        pq.pop();

        u = dsu.find(u);
        if (done[u]) {
          continue;
        }

        for (int v : g[u]) {
          if (done[v] && a[u] <= dsu.size(v)) {
            done[u] = 1;
            dsu.merge(u, v);
            break;
          }
        }
        if (!done[u]) {
          continue;
        }

        for (auto i : g[u]) {
          if (!done[i] && visited.find(i) == visited.end()) {
            visited.insert(i);
            pq.push({a[i], i});
          }
        }
      }
      for (int i : visited) {
        start = dsu.find(start);
        if (!dsu.is_same_set(start, i)) {
          g[start].push_back(i);
          g[i].push_back(start);
        } else {
          done[i] = 0;
        }
      }
    }
    cout << (dsu.dsu_size == 1 ? "YES" : "NO") << '\n';
  }
}
