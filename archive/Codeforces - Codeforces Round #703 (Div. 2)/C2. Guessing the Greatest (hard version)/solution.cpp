#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  function<int(int, int)> ask = [](int l, int r) {
    cout << "? " << l << " " << r << endl;
    int res;
    cin >> res;
    return res;
  };
  int p = ask(1, n);
  if (n == 2) {
    cout << "! " << 3 - p << endl;
    return 0;
  }
  int t = n;
  if (p != 1) {
    t = ask(1, p);
  }
  int l, r;
  if (t == p) {
    l = 1;
    r = p - 1;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (ask(m, p) == p) {
        l = m;
      } else {
        r = m - 1;
      }
    }
  } else {
    l = p + 1;
    r = n;
    while (l < r - 1) {
      int m = (l + r) / 2;
      if (ask(p, m) == p) {
        r = m;
      } else {
        l = m + 1;
      }
    }
  }
  if (l == r) {
    if (l != 1) {
      l--;
    } else {
      r++;
    }
  }
  if (ask(l, r) == l) {
    cout << "! " << r << endl;
  } else {
    cout << "! " << l << endl;
  }
}
