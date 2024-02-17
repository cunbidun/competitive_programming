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
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < i; j++) {
        int f = 0;
        for (int k = 0; k < N; k++) {
          if (a[i] % a[k] == 0 && a[j] % a[k] == 0) {
            f = 1;
            break;
          }
        }
        ans += 1 - f;
      }
    }
    cout << ans << '\n';
  }
}
