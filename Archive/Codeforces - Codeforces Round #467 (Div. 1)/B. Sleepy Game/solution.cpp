#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

const int N = 2e5 + 5;
int n, m, s, vis[N], p[N][2], c = 0;
vi a[N];

void dfs(int u, int d) {
  vis[u] = 1;
  for (int v : a[u]) {
    if (p[v][1 - d] == 0) {
      p[v][1 - d] = u;
      dfs(v, 1 - d);
    }
    if (vis[v] == 1) {
      c = 1;
    }
  }
  vis[u] = 2;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    while (k--) {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
  }

  cin >> s;
  p[s][1] = -1;
  dfs(s, 1);

  for (int i = 1; i <= n; i++) {
    if (sz(a[i]) == 0) {
      if (p[i][0] != 0) {
        cout << "Win\n";
        vi l;
        int cur = i;
        while (cur != -1) {
          int nxt = p[cur][sz(l) % 2];8

          l.push_back(cur);
          cur = nxt;
        }
        reverse(all(l));
        for (int j : l) {
          cout << j << " ";
        }
        cout << "\n";
        return 0;
      }
    }
  }
  if (c == 1) {
    cout << "Draw\n";
  } else {
    cout << "Lose\n";
  }
  return 0;
}