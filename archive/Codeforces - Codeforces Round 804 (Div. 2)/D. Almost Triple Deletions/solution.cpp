/**
 *  author: cunbidun
 *  created: Friday, 2023-09-22 20:16:17 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <map>
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
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<int> suff(N + 2);
    vector<vector<int>> f(N + 1, vector<int>(N + 1, -1));

    vector<int> mp(N + 1, 0);
    int mx = 0;
    for (int i = N; i >= 1; i--) {
      mp[a[i]]++;
      mx = max(mx, mp[a[i]]);
      int sz = N - i + 1;
      if (mx * 2 < sz) {
        suff[i] = sz % 2;
      } else {
        suff[i] = mx - (sz - mx);
      }
    }
    for (int i = 1; i <= N; i++) {
      f[0][i] = 0;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
      mp.assign(N + 1, 0);
      mx = 0;
      if ((a[i] == a[i - 1] || i == 1) && f[i - 1][a[i]] != -1) {
        f[i][a[i]] = f[i - 1][a[i]] + 1;
      }
      for (int j = i - 1; j >= 1; j--) {
        mp[a[j]]++;
        mx = max(mx, mp[a[j]]);
        int sz = i - j;
        int num = 0;
        if (mx * 2 < sz) {
          num = sz % 2;
        } else {
          num = mx - (sz - mx);
        }
        if (num == 0 && f[j - 1][a[i]] != -1) {
          f[i][a[i]] = max(f[i][a[i]], 1 + f[j - 1][a[i]]);
        }
      }
      if (suff[i + 1] == 0) {
        ans = max(ans, f[i][a[i]]);
      }
    }
    cout << ans << '\n';
  }
}
