#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n;
vi a[N];

int dfs(int u, int l = 1) {
  int m1 = N, m2 = 0;
  for (int v : a[u]) {
    if (v != l) {
      int cur = dfs(v, u) + 1;
      if (cur > m1) {
        m2 = m1;
        m1 = cur;
      } else {
        m2 = max(m2, cur);
      }
    }
  }
  // cout << u << " " << m1 << " " << m2 << "\n";
  if (m1 == 0) {
    return 0;
  }
  if (m1 == m2) {
    return m1 + 1;
  }
  return m1;
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
  cout << dfs(1) << "\n";
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