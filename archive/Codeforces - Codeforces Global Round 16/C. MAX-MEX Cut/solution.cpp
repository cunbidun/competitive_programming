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
    string s, t;
    cin >> s >> t;
    int ans = 0;
    int b = 1;
    if (s[0] != t[0]) {
      ans = 2;
      b = 0;
    } else {
      ans = '1' - s[0];
    }
    for (int i = 1; i < N; i++) {
      if (s[i] != t[i]) {
        ans += 2;
        b = 0;
      } else if (s[i] == '0') {
        if (b && s[i - 1] == '1') {
          ans += 2;
          b = 0;
        } else {
          ans++;
          b = 1;
        }
      } else {
        if (b && s[i - 1] == '0') {
          ans++;
          b = 0;
        } else {
          b = 1;
        }
      }
    }
    cout << ans << '\n';
  }
}
