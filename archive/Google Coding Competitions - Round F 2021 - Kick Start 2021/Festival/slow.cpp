#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int D, N, K;
    cin >> D >> N >> K;
    vector<array<int, 3>> a;
    for (int i = 0; i < N; i++) {
      int h, s, e;
      cin >> h >> s >> e;
      a.push_back({h, s, e});
    }
    int ans = 0;
    for (int i = 1; i <= D; i++) {
      vector<int> H;
      for (auto [h, s, e] : a) {
        if (s <= i && i <= e) {
          H.push_back(h);
        }
      }
      sort(H.begin(), H.end());
      reverse(H.begin(), H.end());
      int cur = 0;
      for (int j = 0; j < min(K, (int)H.size()); j++) {
        cur += H[j];
      }
      ans = max(ans, cur);
    }
    cout << ans << '\n';
  }
}
