#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 1;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int dsu_size) : dsu_size(dsu_size) {
    p.assign(dsu_size + 1, 0);
    rank.assign(dsu_size + 1, 0);
    child.assign(dsu_size + 1, 0);
    for (int i = 1; i <= dsu_size; i++) {
      p[i] = i;
      child[i] = 1;
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

int n, m;
int p[N][20], mw[N][20], lvl[N], ch[N];
ll ans[N], mst = 0;
vector<pair<int, pair<int, ii>>> edge;
vector<ii> a[N];

void dfs(int u, int l) {
  for (ii v : a[u]) {
    if (v.first != l) {
      lvl[v.first] = lvl[u] + 1;
      p[v.first][0] = u;
      mw[v.first][0] = v.second;
      dfs(v.first, u);
    }
  }
}

int lca(int u, int v) {
  int res = 0;
  if (lvl[u] < lvl[v])
    swap(u, v);

  for (int i = 19; i >= 0; i--) {
    if (lvl[p[u][i]] >= lvl[v]) {
      res = max(res, mw[u][i]);
      u = p[u][i];
    }
  }

  if (u == v)
    return res;

  for (int i = 19; i >= 0; i--) {
    if (p[u][i] != p[v][i]) {
      res = max(res, mw[u][i]);
      res = max(res, mw[v][i]);
      u = p[u][i];
      v = p[v][i];
    }
  }

  int add = max(mw[u][0], mw[v][0]);
  return max(add, res);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  union_find dsu(n);
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    edge.push_back({w, {i, {u, v}}});
  }
  sort(all(edge));

  for (int i = 0; i < sz(edge); i++) {
    int w = edge[i].first;
    int u = edge[i].second.second.first;
    int v = edge[i].second.second.second;
    if (!dsu.is_same_set(u, v)) {
      ch[i] = 1;
      mst += w;
      dsu.merge(u, v);
      a[u].push_back({v, w});
      a[v].push_back({u, w});
    }
  }

  lvl[1] = 1;
  dfs(1, 1);

  for (int j = 1; j < 20; j++) {
    for (int i = 1; i <= n; i++) {
      p[i][j] = p[p[i][j - 1]][j - 1];
      mw[i][j] = max(mw[i][j - 1], mw[p[i][j - 1]][j - 1]);
    }
  }

  for (int i = 0; i < sz(edge); i++) {
    int id = edge[i].second.first;
    if (ch[i]) {
      ans[id] = mst;
    } else {
      int w = edge[i].first;
      int u = edge[i].second.second.first;
      int v = edge[i].second.second.second;
      ans[id] = mst + w - lca(u, v);
    }
  }

  for (int i = 1; i <= m; i++) {
    cout << ans[i] << "\n";
  }
}