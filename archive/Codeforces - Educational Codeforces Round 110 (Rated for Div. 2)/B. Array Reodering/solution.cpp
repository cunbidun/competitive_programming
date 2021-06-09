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
    vector<int> o, e;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      if (x % 2 == 0) {
        e.push_back(x);
      } else {
        o.push_back(x);
      }
    }
    for (int i : o) {
      e.push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        if (__gcd(e[i], 2 * e[j]) > 1) {
          ans++;
        }
      }
    }
    cout << ans << '\n';
  }
}
