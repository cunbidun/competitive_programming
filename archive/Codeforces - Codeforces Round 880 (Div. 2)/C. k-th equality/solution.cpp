/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-18 10:02:33 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<long long> mn(10, 1), mx(10);
  for (int i = 2; i < 8; i++) {
    mn[i] = mn[i - 1] * 10;
  }
  for (int i = 1; i <= 6; i++) {
    mx[i] = mn[i + 1] - 1;
  }

  int T;
  cin >> T;
  while (T--) {
    long long A, B, C, k;
    cin >> A >> B >> C >> k;
    long long total = 0;
    for (int a = mn[A]; a <= mx[A]; a++) {
      long long b1 = max(mn[B], mn[C] - a);
      long long b2 = min(mx[B], mx[C] - a);
      auto num = max(b2 - b1 + 1, 0LL);
      int d = 0;
      if (total + num >= k) {
        long long b = b1 + k - total - 1;
        cout << a << " + " << b << " = " << a + b << "\n";
        d = 1;
      }
      total += num;
      if (d) {
        break;
      }
    }
    if (total < k) {
      cout << -1 << '\n';
    }
  }
}
