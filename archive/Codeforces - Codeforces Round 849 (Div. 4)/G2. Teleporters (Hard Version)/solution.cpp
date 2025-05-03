#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, C;
    cin >> N >> C;
    vector<array<int, 2>> a(N + 1);
    vector<int> b(N + 1);
    vector<int> o(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> o[i];
      b[i] = o[i] + min(i, N - i + 1);
      a[i] = {o[i] + min(i, N - i + 1), i};
    }
    sort(a.begin(), a.end());
    vector<int> pos(N + 1);
    for (int i = 0; i <= N; i++) {
      pos[a[i][1]] = i;
    }
    vector<long long> sum(N + 1);
    for (int i = 1; i <= N; i++) {
      sum[i] = sum[i - 1] + a[i][0];
    }
    int ans = 0;
    auto solve = [&](int i, int c) {
      int l = 0, r = N;
      while (l < r) {
        int m = (l + r + 1) / 2;
        long long actual_sum = sum[m];
        if (m >= pos[i]) {
          actual_sum -= b[i];
        }
        if (actual_sum > c) {
          r = m - 1;
        } else {
          l = m;
        }
      }
      // cout << l << '\n';
      if (l >= pos[i]) {
        l--;
      }
      return l;
    };
    // cout << solve(3, 3) << '\n';
    for (int i = 1; i <= N; i++) {
      if (C >= i + o[i]) {
        ans = max(ans, 1 + solve(i, C - i - o[i]));
        // cout << i << ' ' << solve(i, C - i - o[i]) << '\n';
      }
    }
    cout << ans << '\n';
  }
}
