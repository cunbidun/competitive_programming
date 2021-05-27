#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;

vi a[N];
int n, m, f[N], g[N], ans[N];

int dfs(int u, int l = 1) {
  int cur = 1;
  for (int v : a[u]) {
    if (v != l) {
      cur = (1LL * cur * (dfs(v, u) + 1)) % m;
    }
  }
  return f[u] = cur;
}

void cal(int u, int above, int l = 1) {
  vi c;
  for (int v : a[u]) {
    if (v != l) {
      c.push_back(v);
    }
  }
  vi left(sz(c) + 3), right(sz(c) + 3);
  left[0] = 1;
  right[sz(c) + 1] = 1;
  for (int i = 1; i <= sz(c); i++) {
    left[i] = (1LL * left[i - 1] * (f[c[i - 1]] + 1)) % m;
  }
  for (int i = sz(c); i >= 1; i--) {
    right[i] = (1LL * right[i + 1] * (f[c[i - 1]] + 1)) % m;
  }
  for (int i = 1; i <= sz(c); i++) {
    int ex = (1LL * left[i - 1] * right[i + 1]) % m;
    int ab = (1LL * ex * (above + 1)) % m;
    ans[c[i - 1]] = (1LL * (ab + 1) * f[c[i - 1]]) % m;
    cal(c[i - 1], ab, u);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  dfs(1);
  cal(1, 0);
  ans[1] = f[1];
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << "\n";
  }
}