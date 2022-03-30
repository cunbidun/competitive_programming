#include <array>
#include <functional>
#include <iostream>
#include <vector>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args> decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun> decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

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

  auto solve = []() -> int {
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 3>>> a(N);
    vector<array<int, 3>> edge(N - 1);
    union_find dsu(2 * N);
    for (int i = 0; i < N - 1; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      if (w != -1) {
        int cnt = 0;
        for (int j = 30; j >= 0; j--) {
          if ((w >> j) & 1) {
            cnt++;
          }
        }
        if (cnt % 2 == 0) {
          dsu.merge(u, v);
          dsu.merge(u + N, v + N);
        } else {
          dsu.merge(u, v + N);
          dsu.merge(u + N, v);
        }
      }
      a[u].push_back({v, w, i});
      a[v].push_back({u, w, i});
      edge[i] = {u, v, w};
    }
    while (M--) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      if (w == 0) {
        dsu.merge(u, v);
        dsu.merge(u + N, v + N);
      }
      if (w == 1) {
        dsu.merge(u, v + N);
        dsu.merge(u + N, v);
      }
    }
    for (int i = 0; i < N; i++) {
      if (dsu.is_same_set(i, i + N)) {
        cout << "NO\n";
        return 0;
      }
      if (!dsu.is_same_set(0, i) && !dsu.is_same_set(0, i + N)) {
        dsu.merge(i, 0);
        dsu.merge(i + N, N);
      }
    }
    cout << "YES\n";

    yc([&](auto dfs, int u, int l = 0, int cur = 0) -> void {
      for (auto [v, w, i] : a[u]) {
        if (v != l) {
          if (w == -1) {
            int cnt = 0;
            for (int j = 30; j >= 0; j--) {
              if ((cur >> j) & 1) {
                cnt++;
              }
            }
            if (dsu.is_same_set(v, 0)) {
              w = cnt % 2;
            } else {
              w = 1 - (cnt % 2);
            }
            edge[i] = {u, v, w};
          }
          dfs(v, u, cur ^ w);
        }
      }
    })(0);
    for (auto [u, v, w] : edge) {
      cout << u + 1 << ' ' << v + 1 << ' ' << w << '\n';
    }
    return 0;
  };

  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
