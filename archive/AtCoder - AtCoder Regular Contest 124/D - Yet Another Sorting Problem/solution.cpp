/**
 *  author: cunbidun
 *  created: Wednesday, 2023-05-03 21:22:48 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
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
  int N, M;
  cin >> N >> M;
  vector<int> a(N + M);
  union_find dsu(N + M);
  for (int i = 0; i < N + M; i++) {
    cin >> a[i];
    a[i]--;
  }
  for (int i = 0; i < N + M; i++) {
    dsu.merge(i, a[i]);
  }

  vector<array<bool, 2>> h(N + M);
  for (int i = 0; i < N + M; i++) {
    if (i < N) {
      h[dsu.find(i)][0] = 1;
    } else {
      h[dsu.find(i)][1] = 1;
    }
  }
  set<int> v;
  int mono0 = 0, mono1 = 0;

  for (int i = 0; i < N + M; i++) {
    auto r = dsu.find(i);
    if (v.find(r) == v.end() && dsu.size(r) > 1) {
      // cout << r << '\n';
      if (!h[r][0] || !h[r][1]) {
        if (h[r][0]) {
          mono0++;
        } else {
          mono1++;
        }
      }
      v.insert(r);
    }
  }
  cout << N + M + 2 * max(mono0, mono1) - dsu.dsu_size << '\n';
}
