#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    string s;
    cin >> s;
    int K;
    cin >> K;
    vector<vector<int>> a(30, vector<int>());
    for (int i = 0; i < K; i++) {
      int u, v;
      char x;
      cin >> x;
      u = x - 'A';
      cin >> x;
      v = x - 'A';
      a[u].push_back(v);
      // cout << u << ' ' << v << '\n';
    }
    vector<vector<int>> dis(30, vector<int>(30, 5000));
    for (int i = 0; i <= 'Z' - 'A'; i++) {
      vector<int> visited(30, 0);
      queue<int> q;
      q.push(i);
      dis[i][i] = 0;
      visited[i] = 1;
      while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u]) {
          if (!visited[v]) {
            q.push(v);
            dis[i][v] = dis[i][u] + 1;
            visited[v] = 1;
          }
        }
      }
    }
    int ans = 1e9;
    for (char c = 'A'; c <= 'Z'; c++) {
      int res = 0;
      for (int i = 0; i < (int)s.size(); i++) {
        if (dis[s[i] - 'A'][c - 'A'] == 5000) {
          res = 1e9;
          break;
        }
        res += dis[s[i] - 'A'][c - 'A'];
      }
      ans = min(ans, res);
    }
    if (ans == 1e9) {
      cout << -1 << '\n';
    } else {
      cout << ans << '\n';
    }
  }
}
