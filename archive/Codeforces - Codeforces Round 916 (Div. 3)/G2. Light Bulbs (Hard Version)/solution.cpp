#include <bits/stdc++.h>

using namespace std;

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

struct scc_dag {
  struct Node {
    int index;
    bool instack;
    int lowest;
    Node() : index(-1), instack(false), lowest(-1) {}
  };
  vector<set<int>> g;
  stack<int> node_stack;
  int N, time, num_scc;
  vector<Node> nodes;
  vector<set<int>> dag;
  union_find dsu;

  scc_dag(int _N) : N(_N), nodes(_N), dsu(_N) {
    g.resize(N);
    dag.resize(N);
    num_scc = 0;
    time = 0;
  }

  void dfs(int u) {
    time++;
    nodes[u].index = nodes[u].lowest = time;
    nodes[u].instack = true;
    node_stack.push(u);
    for (int v : g[u]) {
      if (nodes[v].index == -1) {
        dfs(v);
      }
      if (nodes[v].instack) {
        nodes[u].lowest = min(nodes[u].lowest, nodes[v].lowest);
      }
    }
    if (nodes[u].lowest == nodes[u].index) {
      num_scc++;
      while (true) {
        int v = node_stack.top();
        node_stack.pop();
        nodes[v].instack = false;
        dsu.merge(u, v); // Connect nodes within the same SCC
        if (v == u) {
          break;
        }
      }
    }
  }
  void build_dag() {
    for (int i = 0; i < N; i++) {
      for (int j : g[i]) {
        if (dsu.is_same_set(i, j)) {
          continue;
        }
        dag[dsu.find(i)].insert(dsu.find(j));
      }
    }
  }
  void add_edge(int u, int v) { g[u].insert(v); }
  void find_scc_dag() {
    for (int i = 0; i < N; i++) {
      if (nodes[i].index == -1) {
        dfs(i);
      }
    }
    build_dag();
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N * 2 + 1);
    for (int i = 1; i <= 2 * N; i++) {
      cin >> a[i];
    }
    scc_dag graph(N + 1);
    set<int> current_set;
    vector<int> checked(N * 2 + 1);
    vector<vector<int>> g(N + 1);
    for (int i = 1; i <= 2 * N; i++) {
      if (checked[a[i]]) {
        current_set.erase(checked[a[i]]);
      } else {
        if (!current_set.empty()) {
          int largest = *current_set.rbegin();
          int value = a[largest];
          graph.add_edge(value, a[i]);
        }
        checked[a[i]] = i;
        current_set.insert(i);
      }
    }
    current_set.clear();
    checked.assign(N + 1, 0);
    for (int i = 2 * N; i >= 1; i--) {
      if (checked[a[i]]) {
        current_set.erase(checked[a[i]]);
      } else {
        if (!current_set.empty()) {
          int largest = *current_set.begin();
          int value = a[largest];
          graph.add_edge(value, a[i]);
        }
        checked[a[i]] = i;
        current_set.insert(i);
      }
    }
    graph.find_scc_dag();
    vector<int> has_parent(N + 1);
    for (int i = 1; i <= N; i++) {
      for (int j : graph.dag[i]) {
        has_parent[j] = 1;
      }
    }
    int count = 0;
    int num_way = 1;
    for (int i = 1; i <= N; i++) {
      if (graph.dsu.find(i) == i) {
        if (!has_parent[i]) {
          count++;
          num_way = (1LL * num_way * graph.dsu.size(i) * 2) % 998244353;
        }
      }
    }
    cout << count << ' ' << num_way << '\n';
  }
}
