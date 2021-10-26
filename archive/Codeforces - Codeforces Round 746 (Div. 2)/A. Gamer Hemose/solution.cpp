#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N, H;
    cin >> N >> H;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());
    int time = H / (a[0] + a[1]);
    int ans = time * 2;
    int r = H % (a[0] + a[1]);
    if (r != 0) {
      if (r <= a[0]) {
        ans++;
      } else {
        ans += 2;
      }
    }
    cout << ans << '\n';
  }
}
