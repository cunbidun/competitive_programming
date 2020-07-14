#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

const int N = 1e5 + 1;
const int INF = 2e9;

long long ans = 0;
int n, vis[N], c[N];
vii a[N];

int check(int x) {
  while (x) {
    if (x % 10 != 4 && x % 10 != 7)
      return 0;
    x /= 10;
  }
  return 1;
}

void dfs(int u) {
  vis[u] = 1;
  c[u] = 1;
  for (ii p : a[u]) {
    int v = p.first;
    int l = p.second;
    if (vis[v] || l == 1)
      continue;
    dfs(v);
    c[u] += c[v];
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  ans = 1LL * n * (n - 1) * (n - 2);
  for (int i = 1; i <= n; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    a[u].push_back({v, check(w)});
    a[v].push_back({u, check(w)});
  }
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i);
      ans -= 1LL * c[i] * (c[i] - 1) * (c[i] - 2) + 2LL * c[i] * (c[i] - 1) * (n - c[i]);
    }
  }
  cout << ans << "\n";
}