/**
 *  author: cunbidun
 *  created: Sunday, 2023-09-24 09:18:40 CDT
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
    vector<vector<int>> a(N);
    for (int i = 0; i < N; i++) {
      int m;
      cin >> m;
      for (int j = 0; j < m; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
      }
      sort(a[i].begin(), a[i].end());
    }
    int mn0 = 2e9;
    int mn1 = 2e9;
    for (int i = 0; i < N; i++) {
      mn0 = min(mn0, a[i][0]);
      mn1 = min(mn1, a[i][1]);
    }
    long long ans = 0;
    for (int i = 0; i < N; i++) {
      ans += a[i][1];
    }
    cout << ans + mn0 - mn1 << '\n';
  }
}
