#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, ans;
int p[N], h[N], pp[N];
vi a[N];

int dfs(int u, int l) {
  pp[u] = p[u];
  int good = 0;
  for (int v : a[u]) {
    if (v != l) {
      good += dfs(v, u);
      pp[u] += pp[v];
    }
  }
  if ((h[u] + pp[u]) % 2 != 0) {
    ans = 0;
  }
  int gu = (h[u] + pp[u]) / 2;
  int bu = pp[u] - gu;
  if (bu < 0 || gu < good) {
    ans = 0;
  }
  return gu;
}

int solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    a[i].clear();
    pp[i] = 0;
    cin >> p[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> h[i];
  }

  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    a[x].push_back(y);
    a[y].push_back(x);
  }
  ans = 1;
  dfs(1, 1);
  if (ans == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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
