#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<int> s(300005);

  for (int i = 1; i < 300005; i++) {
    s[i] = s[i - 1] ^ i;
  }
  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (s[a - 1] != b) {
      int nxt = s[a - 1] ^ b;
      if (nxt == a) {
        cout << a + 2 << '\n';
      } else {
        cout << a + 1 << '\n';
      }
    } else {
      cout << a << '\n';
    }
  }
}
