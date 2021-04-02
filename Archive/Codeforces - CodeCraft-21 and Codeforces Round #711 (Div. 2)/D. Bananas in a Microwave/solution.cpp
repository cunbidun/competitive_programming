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
    vector<int> visited(m + 1, 0);
    for (long long k = o[i].t - 1; k <= m; k++) {
      if (!visited[k]) {
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
          if (o[i].t == 1) {
            c = c + (o[i].x + 99999) / 100000;
          } else {
            c = (c * o[i].x + 99999) / 100000;
          }
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    cout << ((f[i] == unvisited) ? -1 : f[i]) << ' ';
  }
  cout << '\n';
}
