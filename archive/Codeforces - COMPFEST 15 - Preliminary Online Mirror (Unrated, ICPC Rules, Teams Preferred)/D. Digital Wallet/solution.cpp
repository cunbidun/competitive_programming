/**
 *  author: cunbidun
 *  created: Wednesday, 2023-09-27 21:23:00 CDT
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
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> a(M + 1);
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      int x;
      cin >> x;
      a[j].push_back(x);
    }
  }
  for (int i = 1; i <= M; i++) {
    sort(a[i].begin(), a[i].end());
    a[i].push_back(0);
    reverse(a[i].begin(), a[i].end());
  }
  vector<vector<long long>> f(M + 1, vector<long long>(K + 2));
  for (int i = 1; i <= M; i++) {
    int mn = max(i - K + 1, 0);
    int mx = i;
    for (int j = mn; j <= mx; j++) {
      long long current_sum = 0;
      for (int k = 0; k <= min(K, N); k++) {
        current_sum += a[i][k];
        int left = (j - k);
        int last_mx = i - 1;
        int last_mn = max(i - 1 - K + 1, 0);
        if (last_mn <= left && left <= last_mx) {
          f[i][j - mn] = max(f[i][j - mn], f[i - 1][left - last_mn] + current_sum);
        }
      }
    }
  }
  cout << f[M][0] << '\n';
}
