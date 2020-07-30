#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 2;
int n, vis[N], a[N], g[N], res = 0, nxt = 0;

void dfs(int u) {
  vis[u] = 1;
  int v = g[u];
  if (vis[v] == 2) {
    nxt = 0;
    vis[u] = 2;
    return;
  }
  if (vis[v] == 1) {
    nxt = v;
    vis[u] = 2;
    return;
  }
  dfs(v);
  vis[u] = 2;
}

void cal(int u, int r) {
  res = min(res, a[u]);
  if (g[u] != r) {
    cal(g[u], r);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> g[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (vis[i] == 0) {
      dfs(i);
      if (nxt == 0) {
        continue;
      }
      res = 1e9;
      cal(nxt, nxt);
      ans += res;
    }
  }
  cout << ans << "\n";
}