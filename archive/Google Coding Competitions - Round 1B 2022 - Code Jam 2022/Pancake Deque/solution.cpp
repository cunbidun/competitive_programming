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
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    int l = 0, r = N - 1;
    int mx = 0;
    int ans = 0;
    while (l <= r) {
      if (a[l] < a[r]) {
        if (a[l] >= mx) {
          ans++;
          mx = a[l];
        }
        l++;
      } else {
        if (a[r] >= mx) {
          ans++;
          mx = a[r];
        }
        r--;
      }
    }
    cout << ans << '\n';
  }
}
