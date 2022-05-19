#include <bits/stdc++.h>
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
    vector<vector<int>> right(N + 1, vector<int>(N + 2));
    vector<vector<int>> left(N + 1, vector<int>(N + 2));

    for (int i = 1; i <= N; i++) {
      for (int j = N; j > i; j--) {
        right[i][j] = right[i][j + 1];
        if (a[j] < a[i]) {
          right[i][j]++;
        }
      }
    }
    for (int i = 2; i <= N; i++) {
      for (int j = 1; j < i; j++) {
        left[i][j] = left[i][j - 1];
        if (a[j] < a[i]) {
          left[i][j]++;
        }
      }
    }
    long long ans = 0;
    for (int i = 1; i <= N; i++) {
      for (int j = i + 1; j <= N; j++) {
        ans += right[i][j + 1] * left[j][i - 1];
      }
    }
    cout << ans << '\n';
  }
}
