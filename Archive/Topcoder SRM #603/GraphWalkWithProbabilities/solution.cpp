#include <bits/stdc++.h>

using namespace std;

class GraphWalkWithProbabilities {
public:
  double findprob(vector<string> g, vector<int> w, vector<int> l, int s) {
    int n = g.size();
    vector<vector<int>> a(n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (g[i][j] == '1') {
          a[i].push_back(j);
        }
      }
    }
    int M = 3000;
    vector<vector<double>> f(n, vector<double>(M, 0));
    for (int d = 1; d < M; d++) {
      for (int i = 0; i < n; i++) {
        for (int j : a[i]) {
          f[i][d] = max(f[i][d], 1.0 * w[j] / 100 + f[j][d - 1] * (1.0 * (100 - w[j] - l[j]) / 100));
        }
      }
    }
    cout << f[s][M - 1] << '\n';
    return f[s][M - 1];
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  GraphWalkWithProbabilities m;
  // m.findprob({"1"}, {1}, {1}, 0);
  m.findprob({"11", "11"}, {2, 3}, {3, 4}, 0);
}
