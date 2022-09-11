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
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    int N;
    cin >> N;
    vector<array<int, 2>> a(N);
    vector<int> ans(N, -1);
    for (int i = 0; i < N; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end());
    int p = 0;
    for (int i = 0; i < N; i++) {
      while (p < N && a[p][0] <= a[i][0] * 2) {
        p++;
      }
      if (p - 1 != i) {
        ans[a[i][1]] = a[p - 1][0];
      } else {
        if (i != 0) {
          ans[a[i][1]] = a[i - 1][0];
        }
      }
    }
    for (int i = 0; i < N; i++) {
      cout << ans[i] << ' ';
    }
    cout << '\n';
  }
}
