#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto sieve = [](int N) -> vector<int> {
    vector<int> spf(N);
    spf[1] = 1;
    for (int i = 2; i < N; i++) {
      spf[i] = i;
    }
    for (int i = 2; i * i < N; i++) {
      if (spf[i] == i) {
        for (int j = i * i; j < N; j += i) {
          if (spf[j] == j) {
            spf[j] = i;
          }
        }
      }
    }
    return spf;
  };
  vector<int> spf = sieve(2e7 + 1);
  int t;
  cin >> t;
  while (t--) {
    long long c, d, x;
    cin >> c >> d >> x;
    vector<long long> n;
    for (long long g = 1; g * g <= x; g++) {
      if (x % g == 0) {
        n.push_back(g);
        if (x / g != g) {
          n.push_back(x / g);
        }
      }
    }

    int ans = 0;
    for (long long g : n) {
      if ((x + d * g) % c == 0) {
        long long l = (x + d * g) / c;
        if (l % g == 0) {
          int cnt = 0;
          int cur = l / g;
          while (cur != 1) {
            cnt++;
            int tmp = spf[cur];
            while (cur % tmp == 0) {
              cur /= tmp;
            }
          }
          ans += 1 << cnt;
        }
      }
    }
    cout << ans << '\n';
  }
}
