/**
 *  author: cunbidun
 *  created: Monday, 2023-01-16 20:34:15 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Dinic {
  struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
  };
  const long long flow_inf = 1e18;
  vector<FlowEdge> edges;
  vector<vector<int>> adj;
  int n, m = 0;
  int s, t;
  vector<int> level, ptr;
  queue<int> q;

  Dinic(int n, int s, int t) : n(n), s(s), t(t) {
    adj.resize(n);
    level.resize(n);
    ptr.resize(n);
  }

  void add_edge(int v, int u, long long cap) {
    edges.emplace_back(v, u, cap);
    edges.emplace_back(u, v, 0);
    adj[v].push_back(m);
    adj[u].push_back(m + 1);
    m += 2;
  }

  bool bfs() {
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (int id : adj[v]) {
        if (edges[id].cap - edges[id].flow < 1)
          continue;
        if (level[edges[id].u] != -1)
          continue;
        level[edges[id].u] = level[v] + 1;
        q.push(edges[id].u);
      }
    }
    return level[t] != -1;
  }

  long long dfs(int v, long long pushed) {
    if (pushed == 0)
      return 0;
    if (v == t)
      return pushed;
    for (int &cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
      int id = adj[v][cid];
      int u = edges[id].u;
      if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
        continue;
      long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
      if (tr == 0)
        continue;
      edges[id].flow += tr;
      edges[id ^ 1].flow -= tr;
      return tr;
    }
    return 0;
  }

  long long flow() {
    long long f = 0;
    while (true) {
      fill(level.begin(), level.end(), -1);
      level[s] = 0;
      q.push(s);
      if (!bfs())
        break;
      fill(ptr.begin(), ptr.end(), 0);
      while (long long pushed = dfs(s, flow_inf)) {
        f += pushed;
      }
    }
    return f;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int H, W, N;
  cin >> H >> W >> N;
  Dinic dinic(H + W + 2 * N + 3, H + W + 2 * N + 1, H + W + 2 * N + 2);
  for (int i = H + W + 1; i <= H + W + N; i++) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int j = a; j <= c; j++) {
      dinic.add_edge(j, i, 1);
    }
    for (int j = H + b; j <= H + d; j++) {
      dinic.add_edge(i + N, j, 1);
    }
    dinic.add_edge(i, i + N, 1);
  }
  for (int i = 1; i <= H; i++) {
    dinic.add_edge(H + W + 2 * N + 1, i, 1);
  }
  for (int i = H + 1; i <= H + W; i++) {
    dinic.add_edge(i, H + W + 2 * N + 2, 1);
  }
  cout << dinic.flow() << '\n';
}
