#include <bits/stdc++.h>

using namespace std;

// skip
// skip
#define st first
#define nd second
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
int p[200005];
vector<iii> e, g;

int find_p(int u) {
  if (u == p[u]) {
    return u;
  }
  p[u] = find_p(p[u]);
  return p[u];
}

void join(int u, int v) {
  p[find_p(u)] = find_p(v);
}

int main() {
  int test;
  cin >> test;
  while (test--) {
    int n, m, k;
    cin >> n >> m >> k;
    e.clear();
    g.clear();
    for (int i = 1; i <= n; i++) {
      p[i] = i;
    }
    for (int i = 1; i <= m; i++) {
      int u, v, w;
      cin >> u >> v >> w;
      if (w <= k) {
        e.push_back(iii(-w, ii(u, v)));
      } else {
        g.push_back(iii(w, ii(u, v)));
      }
    }
    sort(e.begin(), e.end());
    sort(g.begin(), g.end());
    bool eq = false;
    ll cur = 1e9;
    for (int i = 0; i < e.size(); i++) {
      int u = e[i].nd.st;
      int v = e[i].nd.nd;
      ll w = -e[i].st;
      if (find_p(u) == find_p(v)) {
        continue;
      } else {
        join(u, v);
        //cout<<w<<' '<<k<<endl;
        cur = min(cur, k - w);
      }
    }
    ll cur2 = 0;
    for (int i = 0; i < g.size(); i++) {
      int u = g[i].nd.st;
      int v = g[i].nd.nd;
      ll w = g[i].st;
      if (find_p(u) == find_p(v)) {
        continue;
      } else {
        join(u, v);
        //cout<<w<<' '<<k<<endl;
        cur2 += w - k;
      }
    }
    if (cur2 == 0) {
      for (int i = 0; i < g.size(); i++) {
        int u = g[i].nd.st;
        int v = g[i].nd.nd;
        ll w = g[i].st;
        if (w - k < cur) {
          cur2 = w - k;
          break;
        }
      }
    }

    if (cur2 > 0) {
      cout << cur2 << endl;
    } else {
      cout << cur << endl;
    }
  }
  return 0;
}
