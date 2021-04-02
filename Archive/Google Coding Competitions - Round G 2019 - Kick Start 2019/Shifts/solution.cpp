#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N, H;
    cin >> N >> H;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i] ;
    }
    for (int i = 0; i < N; i++) {
      cin >> b[i] ;
    }
    vector<int> f(1 << N);
    vector<vector<int>> s(2);
    for (int state = 0; state < (1 << N); state++) {
      vector<int64_t> cnt(2);
      for (int bit = 0; bit < N; bit++) {
        if((state >> bit) & 1) {
          cnt[0] += a[bit];
          cnt[1] += b[bit];
        } 
      }
      if (cnt[0] >= H) {
        s[0].push_back(state);
      }
      if (cnt[1] >= H) {
        s[1].push_back(state);
        f[state]++;
      }
    }
    for (int i = 0; i < N; i++) {
      for (int mask = (1 << N) - 1; mask >= 0; mask--) {
        if (((mask >> i) & 1) == 1) {
          f[mask ^ (1 << i)] += f[mask];
        }
      }
    }
    int64_t ans = 0;
    for (int state : s[0]) {
      int cur = 0;
      for (int bit = 0; bit < N; bit++) {
        if (((state >> bit) & 1) == 0) {
          cur += (1 << bit);
        }
      }
      ans += f[cur];
    }
    cout << ans << "\n";
  }
}
