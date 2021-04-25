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
    vector<int> cnt(2), cur(2);
    for (int i = 0; i < n; i++) {
      cnt[s[i] - '0']++;
    }
    if (cnt[1] % 2 == 1 || cnt[0] % 2 == 1) {
      cout << "NO\n";
      continue;
    }
    if (s[0] == '0' || s[n - 1] == '0') {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    string a = "", b = "";
    for (int i = 0; i < n; i++) {
      cur[s[i] - '0']++;
      if (s[i] == '1') {
        if (cur[1] <= cnt[1] / 2) {
          a += '(';
          b += '(';
        } else {
          a += ')';
          b += ')';
        }
      } else {
        if (cur[0] % 2 == 0) {
          a += '(';
          b += ')';
        } else {
          a += ')';
          b += '(';
        }
      }
    }
    cout << a << '\n';
    cout << b << '\n';
  }
}
