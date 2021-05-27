#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, a[N];
vi g[N];
ll c[N], s[N];

void dfs(int u) {
  s[u] = a[u];
  if (sz(g[u]) == 0) {
    c[u] = 1;
    return;
  }
  for (int v : g[u]) {
    dfs(v);
    s[u] += s[v];
    c[u] += c[v];
  }
}

int check(ll m) {
  for (int i = 1; i <= n; i++) {
    if ((s[i] + c[i] - 1) / c[i] > m) {
      return 0;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    g[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  dfs(1);
  ll l = 0, r = 1e9 * 3e5;
  while (l < r) {
    ll m = (r + l) / 2;
    if (check(m)) {
      r = m;
    } else {
      l = m + 1;
    }
  }
  cout << l << "\n";
}
