/**
 *  author: cunbidun
 *  created: Saturday, 2023-08-05 17:30:15 CDT
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
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<vector<int>> f(N, vector<int>(N));
  vector<vector<int>> ans(N, vector<int>(N));
  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      f[i][j] = (j * i) % N;
    }
  }

  for (int i = 0; i < N; i++) {
    ans[0][i] = a[i] - f[i][i];
    if (ans[0][i] < 0) {
      ans[0][i] += N;
    }
  }

  for (int i = 1; i < N; i++) {
    for (int j = 0; j < N; j++) {
      ans[i][j] = ans[0][j] + f[i][j];
      if (ans[i][j] >= N) {
        ans[i][j] -= N;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << ans[i][j] << ' ';
    }
    cout << '\n';
  }
}
