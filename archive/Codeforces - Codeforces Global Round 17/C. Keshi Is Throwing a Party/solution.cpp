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
    vector<array<int, 2>> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i][1] >> a[i][0];
    }
    auto check = [&](int m) {
      int cnt = 0;
      for (int i = 0; i < N; i++) {
        if (cnt <= a[i][0] && m - cnt - 1 <= a[i][1]) {
          cnt++;
        }
      }
      return cnt >= m;
    };
    int l = 1, r = N;
    while (l < r) {
      int m = (l + r + 1) / 2;
      if (check(m)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    cout << l << '\n';
  }
}
