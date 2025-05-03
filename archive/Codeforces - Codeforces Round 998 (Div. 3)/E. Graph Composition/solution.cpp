#include <bits/stdc++.h>

namespace std {
template <class Fun> class y_combinator_result {
  Fun fun_;

public:
  template <class T> explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
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
  int T;
  cin >> T;
  while (T--) {
    int N, M1, M2;
    cin >> N >> M1 >> M2;
    union_find dsu(N + 1);
    union_find current_dsu(N + 1);
    vector<vector<pair<int, int>>> a(N + 1);
    for (int i = 0; i < M1; i++) {
      int x, y;
      cin >> x >> y;
      a[x].push_back({y, i});
      a[y].push_back({x, i});
    }
    for (int i = 0; i < M2; i++) {
      int x, y;
      cin >> x >> y;
      dsu.merge(x, y);
    }
    vector<int> disabled(M1 + 1);
    vector<int> visited(N + 1);
    int ans = 0;

    auto dfs = yc([&](auto _dfs, int r, int u) -> void {
      visited[u] = 1;
      current_dsu.merge(r, u);
      for (auto [v, idx] : a[u]) {
        if (disabled[idx]) {
          continue;
        }
        if (!dsu.is_same_set(r, v)) {
          // cout << r << ' ' << v << '\n';
          disabled[idx] = 1;
          ans++;
        } else {
          if (!visited[v])
            _dfs(r, v);
        }
      }
    });

    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        dfs(i, i);
      }
    }
    // cout << ans << '\n';
    for (int i = 1; i <= N; i++) {
      int s = dsu.find(i);
      if (!current_dsu.is_same_set(s, i)) {
        ans++;
        current_dsu.merge(s, i);
      }
    }
    cout << ans << '\n';
  }
}
