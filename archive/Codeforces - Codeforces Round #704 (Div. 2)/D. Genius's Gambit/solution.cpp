#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, k;
  cin >> a >> b >> k;
  if (k == 0) {
    cout << "Yes\n";
    for (int i = 0; i < b; i++) {
      cout << 1;
    }
    for (int i = 0; i < a; i++) {
      cout << 0;
    }
    cout << '\n';
    for (int i = 0; i < b; i++) {
      cout << 1;
    }
    for (int i = 0; i < a; i++) {
      cout << 0;
    }
    cout << '\n';
    return 0;
  }
  if (a == 0) {
    if (k != 0) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      for (int i = 0; i < b; i++) {
        cout << 1;
      }
      cout << '\n';
      for (int i = 0; i < b; i++) {
        cout << 1;
      }
      cout << '\n';
    }
    return 0;
  }
  if (b == 1) {
    if (k != 0) {
      cout << "No\n";
    } else {
      cout << "Yes\n";
      cout << 1;
      for (int i = 0; i < a; i++) {
        cout << 0;
      }
      cout << '\n';
      cout << 1;
      for (int i = 0; i < a; i++) {
        cout << 0;
      }
      cout << '\n';
    }
    return 0;
  }
  if (k > a + b - 2) {
    cout << "No\n";
    return 0;
  }
  cout << "Yes\n";
  string sa = "11";
  string sb = "10";
  int p = a + b - 1 - k;
  int cnt = 0;
  for (int i = a + b - 2; i >= 1; i--) {
    if (i != p) {
      if (cnt < b - 2) {
        sa += "1";
        sb += "1";
        cnt++;
      } else {
        sa += "0";
        sb += "0";
      }
    } else {
      sa += "0";
      sb += "1";
    }
  }
  cout << sa << "\n";
  cout << sb << "\n";
}
