#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    c--;
    string A = "";
    string B = "";
    for (int i = 1; i <= a; i++) {
      if (i <= a - c) {
        A += "1";
      } else {
        A += "0";
      }
    }
    for (int i = 1; i <= b; i++) {
      if (i < b - c) {
        B += "1";
      } else if (i == b - c) {
        B += "2";
      } else {
        B += "0";
      }
    }
    cout << A << ' ' << B << '\n';
  }
}
