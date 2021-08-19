#include <bits/stdc++.h>

namespace std {
template <class Fun>
class y_combinator_result {
  Fun fun_;

public:
  template <class T>
  explicit y_combinator_result(T &&fun) : fun_(std::forward<T>(fun)) {}
  template <class... Args>
  decltype(auto) operator()(Args &&...args) {
    return fun_(std::ref(*this), std::forward<Args>(args)...);
  }
};
template <class Fun>
decltype(auto) yc(Fun &&fun) {
  return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
} // namespace std

using namespace std;

template <class T>
struct max_flow {
  const T INF = numeric_limits<T>::max();

  struct flow_edge {
    int u, v;
    T c, f = T{};
    flow_edge(int _u, int _v, T _c) : u(_u), v(_v), c(_c) {}
  };

  vector<flow_edge> edges;
  vector<vector<int>> adj;
  int n, m = 0, s, t;
  vector<int> lvl, ptr;
  queue<int> q;

  max_flow(int _n) : n(_n) {
    adj.resize(_n), lvl.resize(_n), ptr.resize(_n);
  }

  void add_edge(int u, int v, T cap) {
    edges.push_back({u, v, cap}), edges.push_back({v, u, 0});
    adj[u].push_back(m++), adj[v].push_back(m++);
  }

  bool bfs() {
    fill(ptr.begin(), ptr.end(), 0);
    fill(lvl.begin(), lvl.end(), -1);
    lvl[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int u = q.front();
      q.pop();
      for (int id : adj[u]) {
        if (edges[id].c > edges[id].f && lvl[edges[id].v] == -1) {
          lvl[edges[id].v] = lvl[u] + 1, q.push(edges[id].v);
        }
      }
    }
    return lvl[t] != -1;
  }

  T dfs(int u, T pushed) {
    if (pushed == 0) {
      return 0;
    }
    if (u == t) {
      return pushed;
    }
    for (int &cid = ptr[u]; cid < (int)adj[u].size(); cid++) {
      int id = adj[u][cid];
      int v = edges[id].v;
      if (lvl[u] + 1 == lvl[v]) {
        if (T tr = dfs(v, min(pushed, edges[id].c - edges[id].f))) {
          edges[id].f += tr;
          edges[id ^ 1].f -= tr;
          return tr;
        }
      }
    }
    return 0;
  }

  T cal_max_flow(int _s, int _t) {
    s = _s, t = _t;
    T f = 0;
    while (bfs()) {
      while (T pushed = dfs(s, INF)) {
        f += pushed;
      }
    }
    return f;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  max_flow<int> mf(2 * N + 2);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    mf.add_edge(u, v + N, 1);
  }
  vector<int> from_s(2 * N + 2);
  vector<int> to_t(2 * N + 2);
  for (int i = 0; i < N; i++) {
    mf.add_edge(2 * N, i, 1);
    from_s[i] = mf.m - 2;
  }
  for (int i = 0; i < N; i++) {
    mf.add_edge(i + N, 2 * N + 1, 1);
    to_t[i + N] = mf.m - 2;
  }
  int s = 2 * N;
  int t = 2 * N + 1;

  mf.cal_max_flow(s, t);
  for (int i = 0; i < N; i++) {
    int id = -1;
    for (int j : mf.adj[i]) {
      if (mf.edges[j].f == 1) {
        id = j;
        break;
      }
    }
    if (id == -1) {
      cout << "Mirko\n";
    } else {
      int u = i;
      int v = mf.edges[id].v;
      mf.edges[from_s[u]].c = 0;
      mf.edges[to_t[v]].f = 0;
      if (mf.bfs()) {
        cout << "Mirko\n";
      } else {
        cout << "Slavko\n";
      }
      mf.edges[from_s[u]].c = 1;
      mf.edges[to_t[v]].f = 1;
    }
  }
}
