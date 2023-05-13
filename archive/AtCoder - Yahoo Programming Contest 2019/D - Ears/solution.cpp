/**
 *  author: cunbidun
 *  created: Wednesday, 2023-04-19 22:29:51 CDT
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
  int L;
  cin >> L;
  vector<vector<int>> f(L + 1, vector<int>(5, 1e9));
  vector<int> a(L + 1);
  for (int i = 1; i <= L; i++) {
    cin >> a[i];
  }
  auto get = [&](int x, int i) -> int {
    if (x == 0 || x == 4) {
      return a[i];
    }
    if (x == 1 || x == 3) {
      if (a[i] == 0) {
        return 2;
      }
      return a[i] % 2;
    }
    return 1 - (a[i] % 2);
  };
  for (int i = 0; i < 5; i++) {
    f[0][i] = 0;
  }
  for (int i = 1; i <= L; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k <= j; k++) {
        f[i][j] = min(f[i][j], f[i - 1][k] + get(k, i));
      }
    }
  }
  int ans = 1e9;
  for (int i = 0; i < 5; i++) {
    ans = min(f[L][i], ans);
  }
  cout << ans << '\n';
}
