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
      long long M = 360 * 12 * 10000000000;
      long long b9 = 1000000000;
      long long A, B, C;
      cin >> A >> B >> C;
      vector<long long> v;
      v.push_back(A);
      v.push_back(B);
      v.push_back(C);
      do {
        long long a = v[0];
        long long b = v[1];
        for (int i = 0; i <= 1; i++) {
          for (int j = 0; j <= 12; j++) {
            long long s1 = a + i * M;
            long long s2 = b + j * M;
            if ((s2 - s1) % 11 != 0) {
              continue;
            }
            long long x = (s2 - s1) / 11;
            long long y = s1 - x;
            if (x >= 0 && y >= 0) {
              if ((x + y) % M == a && (12 * x + y) % M == b && (720 * x + y) % M == v[2]) {
                long long h = x / b9 / 60 / 60;
                x %= b9 * 60 * 60;
                long long m = x / b9 / 60;
                x %= b9 * 60;
                long long s = x / b9;
                long long n = x % b9;
                cout << h << ' ' << m << ' ' << s << ' ' << n << '\n';
                return;
              }
            }
          }
        }
      } while (next_permutation(v.begin(), v.end()));
    };
    solve();
  }
}
