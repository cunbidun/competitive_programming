#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, Q;
  cin >> N >> Q;
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  while (Q--) {
    int x;
    cin >> x;
    vector<bool> used(N);
    int turn = 1;
    long long ans = 0;
    while (true) {
      bool done = 1;
      long long mx = 0, p1 = 0, p2 = 0;
      long long mn = 1e18;
      for (int i = 0; i < N; i++) {
        if (!used[i]) {
          done = 0;
          if (a[i] > mx) {
            mx = a[i];
            p1 = i;
          }
          if (mn > abs(x - a[i])) {
            mn = abs(x - a[i]);
            p2 = i;
          }
        }
      }
      if (done) {
        break;
      }
      if (turn == 1) {
        ans += mx;
        used[p1] = 1;
      } else {
        used[p2] = 1;
      }
      turn = 1 - turn;
    }
    cout << ans << '\n';
  }
}
