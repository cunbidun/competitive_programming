#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n / 2; i++) {
      if (s[i] != s[n - i - 1]) {
        cnt++;
      }
    }
    int c0 = 0;
    for (int i = 0; i < n; i++) {
      c0 += '1' - s[i];
    }
    if (cnt == 0) {
      if (c0 % 2 == 0) {
        cout << "BOB\n";
      } else {
        if (c0 == 1) {
          cout << "BOB\n";
        } else {
          cout << "ALICE\n";
        }
      }
      continue;
    }
    if (cnt == 1) {
      c0--;
      if (c0 == 1) {
        cout << "DRAW\n";
      } else {
        cout << "ALICE\n";
      }
      continue;
    }
    cout << "ALICE\n";
  }
}
