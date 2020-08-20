#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 1e5 + 5;
const int INF = 1e9;

int n, m, d, ans = 0, st, en, a[N], ch[N], mx, nxt, p[N];
vi g[N];

void dfs(int u, int l, int dr = 0) {
  if (ch[u] == 1 && mx < dr) {
    nxt = u;
    mx = dr;
  }
  for (int v : g[u]) {
    if (v != l) {
      p[v] = u;
      dfs(v, u, dr + 1);
    }
  }
}

int cal(int u, int l, int dr) {
  if (dr < 0) {
    return 0;
  }
  int cnt = 1;
  for (int v : g[u]) {
    if (v != l) {
      cnt += cal(v, u, dr - 1);
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m >> d;
  for (int i = 1; i <= m; i++) {
    int x;
    cin >> x;
    ch[x] = 1;
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (ch[i]) {
      mx = 0;
      nxt = i;
      p[i] = i;
      dfs(i, i);
      st = nxt;
      mx = 0;
      p[nxt] = i;
      dfs(nxt, nxt);
      en = nxt;
      break;
    }
  }
  if (2 * d < mx) {
    cout << 0 << "\n";
    return 0;
  }

  int m = en;
  int cnt = mx / 2;
  while (cnt--) {
    m = p[m];
  }
  if (mx % 2 == 0) {
    cout << cal(m, m, d - mx / 2) << "\n";
  } else {
    cout << cal(m, p[m], d - mx / 2 - 1) + cal(p[m], m, d - mx / 2 - 1) << "\n";
  }
}
