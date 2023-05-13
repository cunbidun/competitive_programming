/**
 *  author: cunbidun
 *  created: Monday, 2023-03-27 21:26:40 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>

using namespace std;

struct MCMF {
  struct Edge {
    int from, to, capacity, cost;
  };

  vector<vector<int>> adj, cost, capacity;

  const int INF = 1e9;

  void shortest_paths(int n, int v0, vector<int> &d, vector<int> &p) {
    d.assign(n, INF);
    d[v0] = 0;
    vector<bool> inq(n, false);
    queue<int> q;
    q.push(v0);
    p.assign(n, -1);

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      inq[u] = false;
      for (int v : adj[u]) {
        if (capacity[u][v] > 0 && d[v] > d[u] + cost[u][v]) {
          d[v] = d[u] + cost[u][v];
          p[v] = u;
          if (!inq[v]) {
            inq[v] = true;
            q.push(v);
          }
        }
      }
    }
  }

  int min_cost_flow(int N, vector<Edge> edges, int K, int s, int t) {
    adj.assign(N, vector<int>());
    cost.assign(N, vector<int>(N, 0));
    capacity.assign(N, vector<int>(N, 0));
    for (Edge e : edges) {
      adj[e.from].push_back(e.to);
      adj[e.to].push_back(e.from);
      cost[e.from][e.to] = e.cost;
      cost[e.to][e.from] = -e.cost;
      capacity[e.from][e.to] = e.capacity;
    }

    int flow = 0;
    int current_cost = 0;
    vector<int> d, p;
    while (flow < K) {
      shortest_paths(N, s, d, p);
      if (d[t] == INF)
        break;

      // find max flow on that path
      int f = K - flow;
      int cur = t;
      while (cur != s) {
        f = min(f, capacity[p[cur]][cur]);
        cur = p[cur];
      }

      // apply flow
      flow += f;
      current_cost += f * d[t];
      cur = t;
      while (cur != s) {
        capacity[p[cur]][cur] -= f;
        capacity[cur][p[cur]] += f;
        cur = p[cur];
      }
    }

    if (flow < K)
      return -1;
    else
      return current_cost;
  }
};

template <typename T, typename U> class BidirectionalMap {
  map<T, U> mp;
  map<U, T> r_mp;
  int add_and_get(T x, U y) {
    if (mp.find(x) == mp.end()) {
      mp[x] = y;
      r_mp[y] = x;
    }
    return mp[x];
  }
  T get_r(U y) { return r_mp[y]; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<string> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  int INF = 1000000;
  int V = N * M;
  vector<MCMF::Edge> edges;
  int total = 0;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (a[i][j] == '#') {
        continue;
      }
      int current_id = i * M + j;
      if (a[i][j] == 'o') {
        cnt++;
        edges.push_back(MCMF::Edge{V, current_id, 1, 0});
        total += N + M - i - j - 1 - 1;
      }
      edges.push_back(MCMF::Edge{current_id, V + 1, 1, N + M - i - j - 1 - 1});
      if (i + 1 < N) {
        int next_id = (i + 1) * M + j;
        if (a[i + 1][j] != '#') {
          edges.push_back(MCMF::Edge{current_id, next_id, INF, 0});
        }
      }
      if (j + 1 < M) {
        int next_id = i * M + (j + 1);
        if (a[i][j + 1] != '#') {
          edges.push_back(MCMF::Edge{current_id, next_id, INF, 0});
        }
      }
    }
  }
  cout << total - MCMF().min_cost_flow(V + 2, edges, cnt, V, V + 1) << '\n';
}
