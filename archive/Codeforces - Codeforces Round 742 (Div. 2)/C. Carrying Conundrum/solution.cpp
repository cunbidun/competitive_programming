#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    stringstream ss;
    if (s.size() == 1) {
      ss << s;
      int n;
      ss >> n;
      cout << n - 1 << '\n';
      continue;
    }
    string n1 = "", n2 = "";
    reverse(s.begin(), s.end());
    for (int i = 0; i < (int)s.size(); i++) {
      if (i % 2 == 0) {
        n1.push_back(s[i]);
      } else {
        n2.push_back(s[i]);
      }
    }

    reverse(n1.begin(), n1.end());
    reverse(n2.begin(), n2.end());
    ss << n1 << ' ' << n2;
    int num1;
    int num2;
    ss >> num1 >> num2;
    // cout << num1 << ' ' << num2 << '\n';
    cout << (num1 + 1) * (num2 + 1) - 2 << '\n';
  }
}
