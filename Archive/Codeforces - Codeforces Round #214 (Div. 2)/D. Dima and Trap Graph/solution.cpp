#include <bits/stdc++.h>

using namespace std;

struct e {
  int v, l, r;
};
struct edge {
  int a, b, l, r;
};

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int _n) {
    dsu_size = _n;
    p.assign(_n, 0);
    rank.assign(_n, 0);
    child.assign(_n, 1);
    for (int i = 0; i < _n; i++) {
      p[i] = i;
    }
  }

  int find(int i) {
    return (p[i] == i) ? i : (p[i] = find(p[i]));
  }

  bool is_same_set(int x, int y) {
    return find(x) == find(y);
  }

  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x);
      y = find(y);
      if (rank[x] > rank[y]) {
        child[x] += child[y];
        p[y] = x;
      } else {
        p[x] = y;
        child[y] += child[x];
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
  }

  int size(int i) {
    return child[find(i)];
  }

  int num_components() {
    return dsu_size;
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  vector<vector<e>> a;
  cin >> n >> m;
  a.assign(n, vector<e>());
  vector<int> lower;
  vector<edge> upper;
  for (int i = 0; i < m; i++) {
    int u, v, l, r;
    cin >> u >> v >> l >> r;
    u--;
    v--;
    a[u].push_back({v, l, r});
    a[v].push_back({u, l, r});
    lower.push_back(l);
    upper.push_back({u, v, l, r});
  }
  sort(lower.begin(), lower.end());
  sort(upper.begin(), upper.end(), [](edge A, edge B) {
    return A.r > B.r;
  });

  auto solve = [&](int ul) -> int {
    union_find dsu(n);
    for (auto [a, b, l, r] : upper) {
      if (l <= ul && ul <= r) {
        dsu.merge(a, b);
        if (dsu.is_same_set(0, n - 1)) {
          return r;
        }
      }
    }
    return -1;
  };

  int ans = 0;
  for (int l : lower) {
    int r = solve(l);
    ans = max(ans, r - l + 1);
  }
  if (ans == 0) {
    cout << "Nice work, Dima!\n";
  } else {
    cout << ans << "\n";
  }
}
