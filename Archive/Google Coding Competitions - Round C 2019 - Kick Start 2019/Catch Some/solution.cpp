#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, K;
    cin >> N >> K;
    vector<int> P(N);
    vector<vector<int>> A(1001, vector<int>(1, 0));
    for (int i = 0; i < N; i++) {
      cin >> P[i];
    }
    for (int i = 0; i < N; i++) {
      int color;
      cin >> color;
      A[color].push_back(P[i]);
    }
    for (int color = 1; color <= 1000; color++) {
      sort(A[color].begin(), A[color].end());
    }
    vector<vector<int>> f(1002, vector<int>(K + 1, INF));
    f[0][0] = 0;
    for (int color = 1; color <= 1000; color++) {
      for (int j = 0; j <= K; j++) {
        for (int k = max(j + 1 - (int)A[color].size(), 0); k <= j; k++) {
          f[color][j] = min(f[color][j], f[color - 1][k] + 2 * A[color][j - k]);
        }
      }
    }
    vector<vector<int>> g(1002, vector<int>(K + 1, INF));
    g[1001][0] = 0;
    for (int color = 1000; color >= 1; color--) {
      for (int j = 0; j <= K; j++) {
        for (int k = max(j + 1 - (int)A[color].size(), 0); k <= j; k++) {
          g[color][j] = min(g[color][j], g[color + 1][k] + 2 * A[color][j - k]);
        }
      }
    }
    int ans = INF;
    for (int color = 0; color < 1000; color++) {
      for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= min((int)A[color + 1].size() - 1, K - i); j++) {
          ans = min(ans, f[color][i] + A[color + 1][j] + g[color + 2][K - j - i]);
        }
      }
    }
    cout << ans << '\n';
  }
}
