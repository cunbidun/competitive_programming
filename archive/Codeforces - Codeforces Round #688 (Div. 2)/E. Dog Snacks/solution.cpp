#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, ok = 1;
vi a[N];

int dfs(int u, int l = 1) {
  int mn = N;
  int mx = 0;
  int cnt = 0;
  for (int v : a[u]) {
    if (v != l) {
      int val = dfs(v, u) - 2;
      if (val < -1) {
        ok = 0;
      }
      if (val == -1) {
        cnt++;
      }
      mn = min(mn, val);
      mx = max(mx, val);
    }
  }
  if (mn == N) {
    return m;
  }
  if (cnt > 1) {
    ok = 0;
  }
  if (cnt == 1) {
    return 0;
  } else {
    return mx + 1;
  }
}

int check() {
  ok = 1;
  dfs(1);
  return ok;
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    a[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  int l = 1, r = n;
  while (l < r) {
    m = (l + r) / 2;
    if (check()) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
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
