#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    auto solve = []() {
      int N, A, B;
      cin >> N >> A >> B;
      vector<int> a(500);
      for (int i = 1; i <= N; i++) {
        cin >> a[i];
      }
      int p = -1;
      for (int i = 499; i >= 0; i--) {
        if (a[i] != 0) {
          p = i;
          break;
        }
      }
      for (int i = p; i < 499; i++) {
        vector<long long> f(499);
        f[i] = 1;
        int d = 1;
        for (int j = i; j >= 1; j--) {
          long long m = f[j] - a[j];
          if (m < 0) {
            d = 0;
            break;
          }
          if (j >= A) {
            f[j - A] += m;
          }
          if (j >= B) {
            f[j - B] += m;
          }
        }
        if (d) {
          cout << i << '\n';
          return;
        }
      }
      cout << "IMPOSSIBLE\n";
    };
    solve();
  }
}
