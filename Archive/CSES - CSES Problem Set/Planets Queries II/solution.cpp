#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, visited[N], lvl[N], nxt[N][20];
vi a[N];

void dfs(int u) {
  if (visited[u]) {
    return;
  }
  visited[u] = 1;
  dfs(nxt[u][0]);
  lvl[u] = lvl[nxt[u][0]] + 1;
}

int jump(int x, int step) {
  if (step <= 0) {
    return x;
  }
  for (int i = 19; i >= 0; i--) {
    if (((step >> i) & 1) == 1) {
      x = nxt[x][i];
    }
  }
  return x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> nxt[i][0];
  }
  for (int j = 1; j <= 19; j++) {
    for (int i = 1; i <= n; i++) {
      nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  while (m--) {
    int x, y;
    cin >> x >> y;
    if (jump(x, lvl[x] - lvl[y]) == y) {
      cout << lvl[x] - lvl[y] << "\n";
    } else {
      int e = jump(x, lvl[x]);
      (jump(e, lvl[e] - lvl[y]) == y) ? cout << lvl[x] + lvl[e] - lvl[y] << "\n"
                                      : cout << -1 << "\n";
    }
  }
}