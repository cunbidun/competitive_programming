#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, m, vis[N];
vi a[N];

void dfs(int u) {
  vis[u] = 1;
  for (int v : a[u]) {
    if (!vis[v]) {
      dfs(v);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[v].push_back(u);
    a[u].push_back(v);
  }
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      cnt++;
      dfs(i);
    }
  }
  cout << cnt - 1 << "\n";
}