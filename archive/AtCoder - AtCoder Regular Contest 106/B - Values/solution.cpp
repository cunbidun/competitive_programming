#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, a[N], b[N], vis[N];
vi g[N];
ll c1 = 0, c2 = 0;
void dfs(int u) {
  c1 += a[u];
  c2 += b[u];
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      c1 = 0;
      c2 = 0;
      dfs(i);
      if (c1 != c2) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
}
