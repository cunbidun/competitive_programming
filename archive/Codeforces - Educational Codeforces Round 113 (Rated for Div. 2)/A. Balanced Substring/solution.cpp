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
    string s;
    cin >> s;
    int ok = 0;
    for (int i = 1; i < (int)s.size(); i++) {
      if (s[i] != s[i - 1]) {
        ok = 1;
        cout << i << ' ' << i + 1 << '\n';
        break;
      }
    }
    if (!ok) {
      cout << -1 << ' ' << -1 << '\n';
    }
  }
}
