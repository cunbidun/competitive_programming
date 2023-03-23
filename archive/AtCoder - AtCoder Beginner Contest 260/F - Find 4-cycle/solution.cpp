/**
 *  author: cunbidun
 *  created: Sunday, 2023-02-19 10:29:44 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int S, T, M;
  cin >> S >> T >> M;
  vector<vector<int>> a(S);
  for (int i = 0; i < M; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
  }
  vector<vector<vector<int>>> f(T, vector<vector<int>>(T));
  for (int i = 0; i < S; i++) {
    for (int j = 0; j < (int)a[i].size(); j++) {
      for (int k = 0; k < (int)a[i].size(); k++) {
        if (j != k) {
          f[a[i][j] - S][a[i][k] - S].push_back(i);
          if (f[a[i][j] - S][a[i][k] - S].size() == 2) {
            cout << a[i][j] + 1 << ' ' << a[i][k] + 1 << ' ' << f[a[i][j] - S][a[i][k] - S][0] + 1 << ' '
                 << f[a[i][j] - S][a[i][k] - S][1] + 1 << '\n';
            return 0;
          }
        }
      }
    }
  }
  cout << -1 << '\n';
}
