#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;

int d[80][80][80];
array<int, 3> p[80][80][80];
int v[80][80][80];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  int a, b, c;
  cin >> a >> b >> c;
  a--, b--, c--;
  vector<string> s(N);
  for (int i = 0; i < N; i++) {
    cin >> s[i];
  }
  queue<array<int, 3>> q;
  q.push({a, b, c});
  d[a][b][c] = 0;
  p[a][b][c] = {a, b, c};
  v[a][b][c] = 1;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();
    for (int i = 0; i < N; i++) {
      if (i != u[0] && i != u[1] && i != u[2]) {
        if (s[u[0]][i] == s[u[1]][u[2]] && !v[i][u[1]][u[2]]) {
          v[i][u[1]][u[2]] = 1;
          p[i][u[1]][u[2]] = u;
          d[i][u[1]][u[2]] = d[u[0]][u[1]][u[2]] + 1;
          q.push({i, u[1], u[2]});
        }
      }
    }
    for (int i = 0; i < N; i++) {
      if (i != u[0] && i != u[1] && i != u[2]) {
        if (s[u[1]][i] == s[u[0]][u[2]] && !v[u[0]][i][u[2]]) {
          v[u[0]][i][u[2]] = 1;
          p[u[0]][i][u[2]] = u;
          d[u[0]][i][u[2]] = d[u[0]][u[1]][u[2]] + 1;
          q.push({u[0], i, u[2]});
        }
      }
    }
    for (int i = 0; i < N; i++) {
      if (i != u[0] && i != u[1] && i != u[2]) {
        if (s[u[2]][i] == s[u[0]][u[1]] && !v[u[0]][u[1]][i]) {
          v[u[0]][u[1]][i] = 1;
          p[u[0]][u[1]][i] = u;
          d[u[0]][u[1]][i] = d[u[0]][u[1]][u[2]] + 1;
          q.push({u[0], u[1], i});
        }
      }
    }
  }
  vector<int> l{0, 1, 2};
  int mn = INF;
  array<int, 3> f;
  do {
    if (v[l[0]][l[1]][l[2]] && mn > d[l[0]][l[1]][l[2]]) {
      mn = d[l[0]][l[1]][l[2]];
      f = {l[0], l[1], l[2]};
    }
  } while (next_permutation(l.begin(), l.end()));
  if (mn == INF) {
    cout << -1 << '\n';
    return 0;
  }
  cout << mn << '\n';
  vector<array<int, 2>> path;
  while (true) {
    if (f[0] == a && f[1] == b && f[2] == c) {
      break;
    }
    auto par = p[f[0]][f[1]][f[2]];
    for (int i = 0; i < 3; i++) {
      if (f[i] != par[i]) {
        path.push_back({par[i], f[i]});
        break;
      }
    }
    f = par;
  }
  reverse(path.begin(), path.end());
  for (auto [i, j] : path) {
    cout << i + 1 << ' ' << j + 1 << '\n';
  }
}
