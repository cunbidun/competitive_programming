#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, ans[N];
vector<ii> a[N];

void dfs(int u) {
  for (ii p : a[u]) {
    int v = p.first;
    int c = p.second;
    if (ans[v] != 0) {
      continue;
    }
    if (ans[u] == c) {
      ans[v] = (c < n) ? c + 1 : c - 1;
    } else {
      ans[v] = c;
    }
    dfs(v);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, c;
    cin >> u >> v >> c;
    a[u].push_back({v, c});
    a[v].push_back({u, c});
  }
  ans[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
}