/**
 *  author: cunbidun
 *  created: Sunday, 2023-06-11 11:49:48 CDT
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
    vector<int> a(N + 1);
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
    }
    // at most
    vector<vector<array<int, 2>>> f(N + 1, vector<array<int, 2>>(N + 1));
    for (int i = 1; i <= N; i++) {
      if (a[i - 1] < a[i]) {
        f[0][i][1] = i;
      } else {
        break;
      }
    }
    for (int g = 1; g <= N; g++) {
      for (int i = 1; i <= N; i++) {
        f[g][i][0] = max(f[g][i - 1][0], f[g - 1][i - 1][1]); // not selected
        if (a[i - 1] < a[i]) {
          f[g][i][1] = f[g][i - 1][1] + 1;
        }
        for (int j = 0; j < i - 1; j++) {
          if (a[j] < a[i]) {
            f[g][i][1] = max(f[g][i][1], f[g - 1][j][1] + 1);
          }
        }
      }
    }
    for (int i = 1; i <= N; i++) {
      cout << N - max(f[i][N][0], f[i][N][1]) << ' ';
    }
    cout << '\n';
  }
}
