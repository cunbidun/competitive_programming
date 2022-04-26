#include <array>
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
    vector<vector<int>> a(N + 1, vector<int>(N + 1));
    int h1 = 0, h2 = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= N; j++) {
        cin >> a[i][j];
        if (i % 2 == 1 && j % 2 == 1 && i + j <= N) {
          h1 ^= a[i][j];
        }
        if (i % 2 == 0 && j % 2 == 1 && i > j) {
          h2 ^= a[i][j];
        }
        a[i][j] = a[i][j] ^ a[i][j - 1] ^ a[i - 1][j] ^ a[i - 1][j - 1];
      }
    }
    int cur = 0;
    auto get = [&](int x1, int y1, int x2, int y2) {
      return a[x2][y2] ^ a[x2][y1 - 1] ^ a[x1 - 1][y2] ^ a[x1 - 1][y1 - 1];
    };
    int ans = 0;
    for (int i = 1; i <= N / 2; i++) {
      cur = get(i, i, N - i + 1, N - i + 1) ^ cur;
      ans ^= cur;
    }
    cout << (ans ^ h1 ^ h2) << '\n';
  }
}
