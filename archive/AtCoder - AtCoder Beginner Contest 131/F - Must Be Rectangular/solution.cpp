/**
 *  author: cunbidun
 *  created: Tuesday, 2023-04-25 22:08:36 CDT
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
  int N;
  cin >> N;

  union_find dsuX(1e5 + 1), dsuY(1e5 + 1);
  vector<vector<int>> X(1e5 + 1), Y(1e5 + 1);
  vector<set<int>> rootX(1e5 + 1), rootY(1e5 + 1);
  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    X[x].push_back(y);
    Y[y].push_back(x);
  }
  for (int i = 0; i <= 1e5; i++) {
    for (int j = 1; j < (int)X[i].size(); j++) {
      dsuY.merge(X[i][j], X[i][j - 1]);
    }
  }
  for (int i = 0; i <= 1e5; i++) {
    for (int j = 1; j < (int)Y[i].size(); j++) {
      dsuX.merge(Y[i][j], Y[i][j - 1]);
    }
  }
  for (int i = 0; i <= 1e5; i++) {
    for (int j : X[i]) {
      rootX[dsuX.find(i)].insert(j);
    }
  }
  for (int i = 0; i <= 1e5; i++) {
    for (int j : Y[i]) {
      rootY[dsuY.find(i)].insert(j);
    }
  }
  long long ans = 0;
  for (int i = 0; i <= 1e5; i++) {
    if (!rootX[i].empty()) {
      auto j = *rootX[i].begin();
      ans += 1LL * rootX[i].size() * rootY[dsuY.find(j)].size();
    }
  }
  cout << ans - N << '\n';
}
