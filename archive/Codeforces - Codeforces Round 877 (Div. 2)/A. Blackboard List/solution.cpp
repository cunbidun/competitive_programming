/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-04 09:49:24 CDT
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
  while (T--) {
    int N;
    cin >> N;
    vector<int> a(N);
    int mn = 1e9 + 7;
    int mx = 0;
    int ch = 0;
    for (int i = 0; i < N; i++) {
      cin >> a[i];
      mn = min(mn, a[i]);
      mx = max(mx, a[i]);
      if (a[i] < 0) {
        ch = 1;
      }
    }
    if (ch) {
      cout << mn << '\n';
    } else {
      cout << mx << '\n';
    }
  }
}
