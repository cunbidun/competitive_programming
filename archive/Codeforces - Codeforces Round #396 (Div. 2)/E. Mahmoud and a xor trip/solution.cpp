#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
int n, a[N], num_child[N];
ll f[N][21], res;
vector<int> g[N];

int count_children(int u, int l) {
  num_child[u] = 1;
  for (int v : g[u]) {
    if (v != l) {
      num_child[u] += count_children(v, u);
    }
  }
  return num_child[u];
}

int dfs(int u, int l, int cur) {
  for (int v : g[u]) {
    if (v != l) {
      f[u][cur] += dfs(v, u, cur);
    }
  }
  if (((a[u] >> cur) & 1) == 1) {
    ll tmp = f[u][cur];
    for (int v : g[u]) {
      if (v != l) {
        tmp -= f[v][cur];
        res += f[v][cur] * tmp;
      }
    }
    tmp = num_child[u] - 1 - f[u][cur];
    for (int v : g[u]) {
      if (v != l) {
        tmp -= num_child[v] - f[v][cur];
        res += (num_child[v] - f[v][cur]) * tmp;
      }
    }
    res += num_child[u] - f[u][cur];
    return f[u][cur] = num_child[u] - f[u][cur];
  } else {
    ll tmp = f[u][cur];
    for (int v : g[u]) {
      if (v != l) {
        tmp -= f[v][cur];
        res += (num_child[v] - f[v][cur]) * tmp;
      }
    }
    tmp = num_child[u] - 1 - f[u][cur];
    for (int v : g[u]) {
      if (v != l) {
        tmp -= num_child[v] - f[v][cur];
        res += f[v][cur] * tmp;
      }
    }
    res += f[u][cur];
    return f[u][cur];
  }
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
  count_children(1, 1);
  ll ans = 0;
  for (int i = 0; i <= 20; i++) {
    res = 0;
    dfs(1, 1, i);
    ans += (1LL << i) * res;
  }
  cout << ans << "\n";
}