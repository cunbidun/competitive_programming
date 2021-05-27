#include <bits/stdc++.h>

using namespace std;

class BigOEasy {
public:
  string isBounded(vector<string> graph) {
    int n = graph.size();
    vector<vector<int>> a(n);
    vector<vector<int>> p(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (graph[i][j] == 'Y') {
          a[i].push_back(j);
          p[i][j] = 1;
        }
      }
    }
    for (int k = 0; k < n; k++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          p[i][j] = p[i][j] || (p[i][k] & p[k][j]);
        }
      }
    }
    for (int i = 0; i < n; i++) {
      int cnt = 0;
      for (int j : a[i]) {
        cnt += p[j][i];
      }
      if (cnt >= 2) {
        cout << "Unbounded\n";
        return "Unbounded";
      }
    }
    cout << "Bounded\n";
    return "Bounded";
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  BigOEasy m;
  m.isBounded({"NYY",
               "YNY",
               "YYN"});
}
