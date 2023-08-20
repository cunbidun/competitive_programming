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
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    while (Q--) {
      int L, R;
      cin >> L >> R;
      L--, R--;
      ll s = 0, x = 0;
      for (int i = L; i <= R; i++) {
        s += a[i];
        x ^= a[i];
      }
      ll mx = s - x;
      int mn = 1e9;
      int pl = 0, pr = 0;
      for (int i = L; i <= R; i++) {
        ll sf = 0, xf = 0;
        for (int j = i; j <= R; j++) {
          sf += a[j];
          xf ^= a[j];
          if (sf - xf == mx && j - i + 1 < mn) {
            mn = j - i + 1;
            pl = i, pr = j;
          }
        }
      }
      cout << pl + 1 << ' ' << pr + 1 << '\n';
    }
  }
}
