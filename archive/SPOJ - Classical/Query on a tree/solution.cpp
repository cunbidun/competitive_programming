#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e4 + 5;
int n, cnt;
vector<vector<ii>> a;
ii edge[N];
int st[N * 4], num_child[N], in[N], out[N], p[N], lvl[N], head[N];

void update(int i, int l, int r, int p, int v) {
  if (p < l || r < p) {
    return;
  }
  if (l == r) {
    st[i] = v;
    return;
  }
  int m = (l + r) / 2;
  update(i * 2, l, m, p, v);
  update(i * 2 + 1, m + 1, r, p, v);
  st[i] = max(st[i * 2], st[i * 2 + 1]);
}

int get_max(int i, int l, int r, int tl, int tr) {
  if (tr < l || r < tl) {
    return 0;
  }
  if (tl <= l && r <= tr) {
    return st[i];
  }
  int m = (l + r) / 2;
  return max(get_max(i * 2, l, m, tl, tr), get_max(i * 2 + 1, m + 1, r, tl, tr));
}

int dfs(int u = 1, int l = 1) {
  num_child[u] = 1;
  for (ii &v : a[u]) {
    if (v.first != l) {
      p[v.first] = u;
      lvl[v.first] = lvl[u] + 1;
      num_child[u] += dfs(v.first, u);
      if (num_child[v.first] > num_child[a[u][0].first] || a[u][0].first == l) {
        swap(v, a[u][0]);
      }
    }
  }
  return num_child[u];
}

void hld(int u = 1, int l = 1) {
  in[u] = ++cnt;
  for (ii v : a[u]) {
    if (v.first != l) {
      head[v.first] = ((v == a[u][0]) ? head[u] : v.first);
      hld(v.first, u);
      update(1, 1, n, in[v.first], v.second);
    }
  }
  out[u] = cnt;
}

int query(int u, int v) {
  int res = 0;
  while (1) {
    if (in[head[u]] <= in[v] && out[v] <= out[head[u]]) {
      break;
    }
    res = max(res, get_max(1, 1, n, in[head[u]], in[u]));
    u = p[head[u]];
  }
  while (head[v] != head[u]) {
    res = max(res, get_max(1, 1, n, in[head[v]], in[v]));
    v = p[head[v]];
  }
  if (lvl[u] > lvl[v]) {
    swap(u, v);
  }
  res = max(res, get_max(1, 1, n, in[u] + 1, in[v]));
  return res;
}

void solve() {
  scanf("%d", &n);
  cnt = 0;
  a.assign(n + 1, {});
  memset(st, 0, sizeof(st));
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    edge[i] = {u, v};
    a[u].push_back({v, w});
    a[v].push_back({u, w});
  }
  dfs();
  head[1] = 1;
  hld();
  while (1) {
    char s[20];
    scanf("%s", s);
    if (s[0] == 'D') {
      break;
    } else if (s[0] == 'Q') {
      int a, b;
      scanf("%d%d", &a, &b);
      printf("%d\n", query(a, b));
    } else {
      int p, v;
      scanf("%d%d", &p, &v);
      if (lvl[edge[p].second] > lvl[edge[p].first]) {
        update(1, 1, n, in[edge[p].second], v);
      } else {
        update(1, 1, n, in[edge[p].first], v);
      }
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }
}
