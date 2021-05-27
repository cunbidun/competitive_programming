#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (s[i] - '0');
    }
    cnt = n - cnt;
    if (cnt % 2 == 0) {
      cout << "BOB\n";
    } else {
      if (cnt == 1) {
        cout << "BOB\n";
      } else {
        cout << "ALICE\n";
      }
    }
  }
}
