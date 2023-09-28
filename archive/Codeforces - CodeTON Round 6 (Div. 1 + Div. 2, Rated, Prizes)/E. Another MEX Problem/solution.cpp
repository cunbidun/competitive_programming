/**
 *  author: cunbidun
 *  created: Tuesday, 2023-09-26 19:15:07 CDT
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
    vector<short> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    vector<vector<bool>> f(N + 1, vector<bool>(N + 2));
    f[0][0] = 1;
    for (int i = 1; i <= N; i++) {
      vector<bool> cnt(N + 2);
      f[i] = f[i - 1];
      int mex = 0;
      int last_mex = 0;
      for (int j = i; j >= 1; j--) {
        if (j != i && a[j] == a[i]) {
          break;
        }
        cnt[a[j]] = 1;
        while (cnt[mex]) {
          mex++;
        }
        if (mex != last_mex && mex > a[i]) {
          for (int val = 0; val <= N; val++) {
            if (f[j - 1][val]) {
              f[i][mex ^ val] = 1;
            }
          }
          last_mex = mex;
        }
      }
    }
    for (int i = N; i >= 0; i--) {
      if (f[N][i]) {
        cout << i << '\n';
        break;
      }
    }
  }
}
