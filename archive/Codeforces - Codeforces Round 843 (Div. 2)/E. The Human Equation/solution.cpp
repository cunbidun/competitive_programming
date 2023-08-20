/**
 *  author: cunbidun
 *  created: Friday, 2023-07-28 22:34:14 CDT
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
    int N;
    cin >> N;
    vector<ll> a(N + 1);
    vector<array<ll, 2>> f(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      f[i][0] = 1e18;
    }
    ll ans = 0;
    for (int i = 1; i <= N; i++) {
      f[i][1] = max(a[i], f[i - 1][1] + a[i]);
      f[i][0] = min(a[i], f[i - 1][0] + a[i]);
      ans = max({ans, abs(f[i][0]), abs(f[i][1])});
    }
    cout << ans << '\n';
  }
}
