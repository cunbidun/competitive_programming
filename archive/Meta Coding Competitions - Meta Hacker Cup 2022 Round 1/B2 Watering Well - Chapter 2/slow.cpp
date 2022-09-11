#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, Q;
    cin >> N;
    vector<long long> tree_x(N), tree_y(N);
    for (int i = 0; i < N; i++) {
      cin >> tree_x[i] >> tree_y[i];
    }
    cin >> Q;
    vector<long long> well_x(Q), well_y(Q);
    for (int i = 0; i < Q; i++) {
      cin >> well_x[i] >> well_y[i];
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < Q; j++) {
        ans += 1LL * (tree_x[i] - well_x[j]) * (tree_x[i] - well_x[j]) +
               1LL * (tree_y[i] - well_y[j]) * (tree_y[i] - well_y[j]);
        ans %= MOD;
      }
    }
    cout << ans << '\n';
  }
}
