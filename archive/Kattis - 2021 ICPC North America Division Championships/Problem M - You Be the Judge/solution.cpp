#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  vector<string> v;
  while (cin >> s) {
    v.push_back(s);
  }
  auto check = [](string s) -> int {
    if (s.size() > 10) {
      return 0;
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] > '9' || s[i] < '0') {
        return 0;
      }
    }
    if (s[0] == '0') {
      return 0;
    }
    return 1;
  };
  if (v.size() != 3) {
    cout << 0 << '\n';
  } else {
    for (string i : v) {
      if (!check(i)) {
        cout << 0 << '\n';
        return 0;
      }
    }
    long long n = stoll(v[0]);
    long long m = stoll(v[1]);
    long long q = stoll(v[2]);
    if (n % 2 == 1 || n < 3 || n > 1e9) {
      cout << 0 << '\n';
      return 0;
    }
    if (n != m + q) {
      cout << 0 << '\n';
      return 0;
    }
    for (int i = 2; i * i <= m; i++) {
      if (m % i == 0) {
        cout << 0 << '\n';
        return 0;
      }
    }
    for (int i = 2; i * i <= q; i++) {
      if (q % i == 0) {
        cout << 0 << '\n';
        return 0;
      }
    }
    cout << 1 << '\n';
  }
}
