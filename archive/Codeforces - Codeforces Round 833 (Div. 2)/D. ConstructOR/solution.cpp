/**
 *  author: cunbidun
 *  created: Thursday, 2023-08-03 21:34:23 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  using ll = long long;
  int T;
  cin >> T;
  while (T--) {
    ll a, b, d;
    cin >> a >> b >> d;
    ll s = (d & -d);
    if ((s > min((a & -a), (b & -b)))) {
      cout << -1 << '\n';
      continue;
    }
    int idx = log2(s);
    ll x = d;
    for (int i = idx + 1; i < 30; i++) {
      if (((x >> i) & 1) == 0) {
        x = x + (d << (i - idx));
      }
    }
    cout << x << '\n';
    assert((x & a) == a);
    assert((x & b) == b);
    assert(x % d == 0);
    assert(x < (1LL << 60));
  }
}
