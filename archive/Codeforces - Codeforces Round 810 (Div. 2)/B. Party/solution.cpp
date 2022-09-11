#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    vector<vector<int>> graph(N);
    for (int i = 0; i < M; i++) {
      int x, y;
      cin >> x >> y;
      x--, y--;
      graph[x].push_back(y);
      graph[y].push_back(x);
    }
    if (M % 2 == 0) {
      cout << 0 << '\n';
    } else {
      int mn = 1e9;
      for (int i = 0; i < N; i++) {
        for (int j : graph[i]) {
          if (graph[i].size() % 2 == 0 && graph[j].size() % 2 == 0) {
            mn = min(mn, a[i] + a[j]);
          }
        }
        if (graph[i].size() % 2 == 1) {
          mn = min(mn, a[i]);
        }
      }
      cout << mn << '\n';
    }
  }
}
