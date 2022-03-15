#include <bits/stdc++.h>

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

template <int D, typename T> struct Vec : public vector<Vec<D - 1, T>> {
  static_assert(D >= 1, "Vector dimension must be greater than zero!");
  template <typename... Args>
  Vec(int n = 0, Args... args)
      : vector<Vec<D - 1, T>>(n, Vec<D - 1, T>(args...)) {}
};
template <typename T> struct Vec<1, T> : public vector<T> {
  Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  int INF = 1e9;
  vector<vector<int>> path(N + 1, vector<int>(N + 1, INF));
  for (int i = 1; i <= N; i++) {
    path[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    path[a][b] = min(path[a][b], t);
  }
  int K, Q;
  cin >> K >> Q;
  K = min(K, N);

  // starting vector s, distance vector d
  auto dijkstra = [&](int s, auto &d) {
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>>
        pq;
    d[s][0][s] = 0;
    pq.push({0, 0, s});
    while (!pq.empty()) {
      int du = pq.top()[0];
      int c = pq.top()[1];
      int u = pq.top()[2];
      pq.pop();
      if (c >= K || du > d[s][c][u]) {
        continue;
      }
      for (int v = 1; v <= N; v++) {
        if (path[u][v] == INF) {
          continue;
        }
        int uv = path[u][v];
        int cost = d[s][c][u] + uv;
        if (d[s][c + 1][v] > cost) {
          d[s][c + 1][v] = cost;
          pq.push({d[s][c + 1][v], c + 1, v});
        }
      }
    }
  };

  Vec<3, int> d(N + 1, N + 1, N + 1, INF);
  for (int i = 1; i <= N; i++) {
    dijkstra(i, d);
  }

  while (Q--) {
    int u, v;
    cin >> u >> v;
    if (d[u][K][v] == INF) {
      cout << -1 << '\n';
    } else {
      cout << d[u][K][v] << '\n';
    }
  }
}
