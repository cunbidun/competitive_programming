#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, M;
    cin >> N >> M;
    vector<vector<array<int, 2>>> a(3 * N + 1);
    for (int i = 1; i <= M; i++) {
      int u, v;
      cin >> u >> v;
      a[u].push_back({v, i}), a[v].push_back({u, i});
    }
    set<int> ind;
    vector<int> matching;
    for (int i = 1; i <= 3 * N; i++) {
      if ((int)ind.size() >= N) {
        cout << "IndSet\n";
        for (int j : ind) {
          cout << j << ' ';
        }
        cout << '\n';
        break;
      }
      if ((int)matching.size() >= N) {
        cout << "Matching\n";
        for (int j : matching) {
          cout << j << ' ';
        }
        cout << '\n';
        break;
      }
      int e = -1;
      set<int>::iterator it;
      for (auto p : a[i]) {
        it = ind.find(p[0]);
        if (it != ind.end()) {
          e = p[1];
          break;
        }
      }
      if (e != -1) {
        matching.push_back(e);
        ind.erase(it);
      } else {
        ind.insert(i);
      }
    }
  }
}
