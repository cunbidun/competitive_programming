#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, M, A, B;
    cin >> N >> M >> A >> B;
    vector<vector<int>> ans(N, vector<int>(M, 1000));
    ans.back().assign(M, 1);
    for (int i = 1; i < N - 1; i++) {
      ans[i][0] = 1;
      ans[i][M - 1] = 1;
    }
    ans[0][0] = A - (N - 2) - M;
    ans[0][M - 1] = B - (N - 2) - M;
    int mn = 1;
    for (int i = 0; i < N; i++) {
      mn = min(mn, *min_element(ans[i].begin(), ans[i].end()));
    }
    if (mn <= 0) {
      cout << "Impossible\n";
      continue;
    }
    cout << "Possible\n";
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        cout << ans[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}
