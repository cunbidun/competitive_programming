#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;

int n, p[N], cnt = 0;
vi a[N];
set<int> c;

void dfs(int u, int l = 1) {
  for (int v : a[u]) {
    if (sz(c) > 0) {
      return;
    }
    if (v == l) {
      continue;
    }
    if (p[v] == 0) {
      p[v] = u;
      dfs(v, u);
    } else {
      c.insert(v);
      int t = u;
      while (t != v) {
        c.insert(t);
        t = p[t];
      }
      return;
    }
  }
}

void cal(int u, int l = -1) {
  cnt++;
  for (int v : a[u]) {
    if (v != l && c.find(v) == c.end()) {
      cal(v, u);
    }
  }
}

void solve() {
  cin >> n;
  c.clear();
  for (int i = 1; i <= n; i++) {
    p[i] = 0;
    a[i].clear();
  }
  for (int i = 1; i <= n; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  p[1] = 1;
  dfs(1);
  ll ans = 0;
  for (int i : c) {
    cnt = 0;
    cal(i);
    ans += 1LL * cnt * (n - cnt) * 2;
    ans += 1LL * cnt * (cnt - 1);
  }
  cout << ans / 2 << "\n";
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