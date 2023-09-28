/**
 *  author: cunbidun
 *  created: Saturday, 2023-09-09 14:44:50 CDT
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <set>
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
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    vector<array<int, 2>> f(N + 1, {-1, 0});
    f[N][0] = 0;
    vector<int> ans;
    int mx = 0;
    for (int i = N - 1; i >= 1; i--) {
      int next = i + a[i] + 1;
      f[i][1] = mx + 1;
      if (next <= N && f[next][0] != -1) {

        f[i][0] = f[next][0] + 1;
      }
      if (next <= N) {
        f[i][1] = max(f[i][1], f[next][1] + 1);
      }
      mx = max(f[i][0], mx);
      if (a[i - 1] == f[i][0]) {
        ans.push_back(0);
      } else if (f[i][0] != -1) {
        ans.push_back(1);
      } else if (a[i - 1] <= f[i][1]) {
        ans.push_back(1);
      } else {
        ans.push_back(2);
      }
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << '\n';
  }
}
