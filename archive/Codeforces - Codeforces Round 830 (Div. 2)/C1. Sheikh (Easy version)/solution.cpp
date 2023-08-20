/**
 *  author: cunbidun
 *  created: Monday, 2023-07-31 23:39:23 CDT
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
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    vector<array<int, 2>> sp;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      if (a[i] != 0) {
        sp.push_back({i, a[i]});
      }
      // s += a[i];
    }
    auto M = sp.size();
    vector<ll> s(M), x(M);
    if (M > 0) {
      s[0] = sp[0][1];
      x[0] = sp[0][1];
      for (int i = 1; i < (int)M; i++) {
        s[i] = s[i - 1] + sp[i][1];
        x[i] = x[i - 1] ^ sp[i][1];
      }
    }
    auto compute = [&](int l, int r) -> ll {
      assert(l <= r);
      if (l == 0) {
        return s[r] - x[r];
      } else {
        return (s[r] - s[l - 1]) - (x[r] ^ x[l - 1]);
      }
    };
    while (Q--) {
      int L, R;
      cin >> L >> R;
      L--, R--;
      int mn = 1e9;
      int pl = L, pr = L;
      if (M != 0) {
        auto lower = lower_bound(sp.begin(), sp.end(), array<int, 2>{L, -1});
        auto upper = upper_bound(sp.begin(), sp.end(), array<int, 2>{R, (int)2e9});
        if (lower != sp.end()) {
          upper--;
          int lower_index = lower - sp.begin();
          int upper_index = upper - sp.begin();
          if (lower_index <= upper_index) {
            ll mx = compute(lower_index, upper_index);
            for (int i = lower_index; i < min((int)M, lower_index + 32); i++) {
              for (int j = upper_index; j >= max({(int)upper_index - 32, 0, i}); j--) {
                if (compute(i, j) == mx) {
                  if (sp[j][0] - sp[i][0] + 1 < mn) {
                    mn = sp[j][0] - sp[i][0] + 1;
                    pl = sp[i][0];
                    pr = sp[j][0];
                  }
                }
              }
            }
          }
        }
      }
      cout << pl + 1 << ' ' << pr + 1 << '\n';
    }
  }
}
