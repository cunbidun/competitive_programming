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
      char x;
      cin >> x;
      a[i] = x - '0';
    }
    int direction = 1;
    int current_pos = 0;
    int mx = 0, mn = 0;
    for (int i = 1; i < N; i++) {
      if (a[i] == a[i - 1]) {
        direction = 1 - direction;
      } else {
        if (direction == 1) {
          current_pos++;
        } else {
          current_pos--;
        }
      }
      mx = max(mx, current_pos);
      mn = min(mn, current_pos);
    }
    cout << mx - mn + 1 << '\n';
  }
}
