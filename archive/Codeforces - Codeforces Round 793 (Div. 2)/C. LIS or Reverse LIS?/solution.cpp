#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    map<int, int> cnt;
    int mx = 0;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      cnt[x]++;
      mx = max(mx, x);
    }
    int ans = 0;
    int left = 0;
    for (auto [k, v] : cnt) {
      if (v >= 2) {
        ans++;
      } else {
        left++;
      }
    }
    cout << ans + (left + 1) / 2 << '\n';
  }
}
