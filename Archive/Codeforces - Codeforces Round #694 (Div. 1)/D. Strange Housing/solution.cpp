#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 3e5 + 5;
int n, m, vis[N], h[N];
vi a[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : a[u]) {
    if (h[u] == 1) {
      h[v] = 0;
    }
  }
  for (int v : a[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}

int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    h[i] = 1;
    vis[i] = 0;
    a[i].clear();
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  h[1] = 1;
  dfs(1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cout << "NO\n";
      return 0;
    }
    ans += h[i];
  }
  cout << "YES\n";
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) {
    if (h[i] == 1) {
      cout << i << " ";
    }
  }
  cout << "\n";
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    solve();
  }
}
