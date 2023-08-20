/**
 *  author: cunbidun
 *  created: Saturday, 2023-07-15 15:54:05 CDT
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
    long long ans = 0;
    vector<vector<int>> a(N * 2, vector<int>(2 * N));
    for (int i = 0; i < 2 * N; i++) {
      for (int j = 0; j < 2 * N; j++) {
        cin >> a[i][j];
        if (i >= N && j >= N) {
          ans += a[i][j];
        }
      }
    }
    cout << ans + min({a[0][N],
                       a[0][2 * N - 1],
                       a[N - 1][N],
                       a[N - 1][2 * N - 1],
                       a[N][0],
                       a[2 * N - 1][0],
                       a[N][N - 1],
                       a[2 * N - 1][N - 1]})
         << '\n';
  }
}
