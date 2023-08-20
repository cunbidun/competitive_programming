/**
 *  author: cunbidun
 *  created: Sunday, 2023-08-06 18:04:21 CDT
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
  int T;
  cin >> T;
  using ll = long long;
  while (T--) {
    ll S, K;
    cin >> S >> K;
    if (S % 10 == 0) {
      cout << S * K << '\n';
      continue;
    }
    if (S % 10 == 5) {
      cout << max(S * K, (S + 5) * (K - 1)) << '\n';
      continue;
    }
    ll ans = 0;
    while (S % 10 != 2) {
      ans = max(ans, S * K);
      S += S % 10;
      K--;
    }
    ll l = 0, r = K / 4;
    auto compute = [&](ll m) -> ll {
      ll new_s = S + (m / 4) * 20;
      for (ll i = 0; i < m % 4; i++) {
        new_s = new_s + new_s % 10;
      }
      return new_s;
    };

    auto check = [&](ll m) -> bool {
      assert(m % 4 == 0);
      auto new_s = compute(m);
      return 4 * new_s < 20 * (K - m - 4);
    };
    while (l < r) {
      ll m = (l + r + 1) / 2;
      if (check(m * 4)) {
        l = m;
      } else {
        r = m - 1;
      }
    }
    l *= 4;
    for (ll i = max(0LL, l - 10); i <= min(K, l + 10); i++) {
      auto new_s = compute(i);
      ans = max(ans, new_s * (K - i));
    }
    cout << ans << '\n';
  }
}
