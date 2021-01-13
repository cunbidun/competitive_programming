#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;

  union_find(int N) {
    dsu_size = N;
    p.assign(N + 1, 0);
    rank.assign(N + 1, 0);
    child.assign(N + 1, 0);
    for (int i = 1; i <= N; i++) {
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

const int N = 2e5 + 5;

int n, m, k;
int mark[N];

struct edge {
  int u, v, w;
};
bool cmp(edge A, edge B) {
  return A.w < B.w;
}

void solve() {
  cin >> n >> m >> k;
  union_find dsu(n);
  vector<edge> es;
  for (int i = 1; i <= m; i++) {
    mark[i] = 0;
  }
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    es.push_back({u, v, w});
  }
  sort(all(es), cmp);

  for (int i = 0; i < m; i++) {
    edge e = es[i];
    if (!dsu.is_same_set(e.u, e.v)) {
      mark[i] = 1;
      dsu.merge(e.u, e.v);
    }
  }
  ll ans = 0;
  int mx = 0;
  int mn = 2e9;
  for (int i = 0; i < m; i++) {
    edge e = es[i];
    if (mark[i]) {
      mx = max(mx, e.w);
      if (e.w >= k) {
        ans += e.w - k;
      }
    }
    mn = min(mn, abs(e.w - k));
  }
  if (mx >= k) {
    cout << ans << "\n";
    return;
  }
  cout << min(k - mx, mn) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
