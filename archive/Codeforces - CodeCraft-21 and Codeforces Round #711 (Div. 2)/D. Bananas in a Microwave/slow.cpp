#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  long long m;
  cin >> n >> m;
  struct op {
    long long t, x, y;
  };
  vector<op> o(n + 1);
  for (int i = 1; i <= n; i++) {
    long long t, x, y;
    cin >> t >> x >> y;
    o[i] = {t, x, y};
  }
  int unvisited = 205;
  vector<int> f(m + 1, unvisited);
  f[0] = 0;
  for (int i = 1; i <= n; i++) {
    if (o[i].t == 1) {
      long long cur = (o[i].x + 99999) / 100000;
      for (long long k = 0; k < cur; k++) {
        int cnt = 0;
        for (int j = k; j <= m; j += cur) {
          if (f[j] != unvisited) {
            cnt = o[i].y;
          } else if (cnt > 0) {
            f[j] = min(f[j], i);
            cnt--;
          }
        }
      }
    } else {
      vector<int> visited(m + 1, 0);
      for (long long k = 1; k <= m; k++) {
        if (visited[k]) {
          continue;
        }
        int cnt = 0;
        long long c = k;
        while (c <= m) {
          visited[c] = 1;
          if (f[c] != unvisited) {
            cnt = o[i].y;
          } else if (cnt > 0) {
            f[c] = min(f[c], i);
            cnt--;
          }
          c = (c * o[i].x + 99999) / 100000;
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    if (f[i] == unvisited) {
      cout << -1 << ' ';
    } else {
      cout << f[i] << ' ';
    }
  }
  cout << '\n';
}
