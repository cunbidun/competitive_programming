#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, p, a[N], nxt[N];
vi g[N];

int dfs(int u, int l = 1) {
  int cur = 0;
  for (int v : g[u]) {
    if (v != l) {
      int dis = dfs(v, u) + (a[u] != a[v]);
      if (cur < dis) {
        cur = dis;
        nxt[u] = v;
      }
    }
  }
  return cur;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  int cur = 1;
  while (nxt[cur] != 0) {
    cur = nxt[cur];
  }
  int ans = dfs(cur, cur);
  cout << (ans + 1) / 2 << "\n";
}
