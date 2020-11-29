#include <bits/stdc++.h>

using namespace std;

const int N = 205;

int n, m, mf = 0;
int res[N][N], p[N];
vector<int> a[N];

void adding_flow() {
  int cur_vertex = m;
  int bottle_neck = 1000000000; // init bottle_neck to very big value
  while (cur_vertex != 1) {
    bottle_neck = min(bottle_neck, res[p[cur_vertex]][cur_vertex]);
    cur_vertex = p[cur_vertex];
  }
  cur_vertex = m;
  while (cur_vertex != 1) {
    res[p[cur_vertex]][cur_vertex] -= bottle_neck; // update residual network
    res[cur_vertex][p[cur_vertex]] += bottle_neck;
    cur_vertex = p[cur_vertex];
  }
  mf += bottle_neck; // add flow value to the max flow
}

int main() {
  cin >> n >> m;

  // construct the graph
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    res[u][v] = w;
    a[u].push_back(v);
    a[v].push_back(u);
  }

  while (true) {
    int f = 0;
    int visited[N];
    memset(visited, 0, sizeof(visited));
    memset(p, 0, sizeof(p));
    queue<int> q;
    q.push(1);
    p[1] = 1;
    while (!q.empty()) { // perform bfs
      int u = q.front();
      q.pop();
      if (u == m) {
        f = 1;
        break;
      }
      for (int v : a[u]) {
        if (res[u][v] != 0 && visited[v] == 0) {
          visited[v] = 1;
          p[v] = u; // save the parents for path tracing
          q.push(v);
        }
      }
    }
    if (!f) { // if there is no augmenting path we break
      break;
    }
    adding_flow();
  }

  cout << mf << "\n";

  return 0;
}