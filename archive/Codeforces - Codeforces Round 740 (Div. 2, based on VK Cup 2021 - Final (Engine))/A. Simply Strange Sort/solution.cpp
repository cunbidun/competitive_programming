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
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int ans = 0;
    while (1) {
      int f = 0;
      for (int i = 1; i < N; i++) {
        f |= a[i - 1] > a[i];
      }
      if (!f) {
        cout << ans << '\n';
        break;
      }
      for (int i = 1 - ((ans + 1) % 2); i < N - 1; i += 2) {
        if (a[i] > a[i + 1]) {
          swap(a[i], a[i + 1]);
        }
      }
      ans++;
    }
  }
}
