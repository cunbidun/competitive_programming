#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  auto ask = [](long long x, long long y) {
    cout << x - (int)1e9 << ' ' << y - (int)1e9 << endl;
    string res;
    cin >> res;
    if (res == "WRONG") {
      exit(0);
    }
    return res;
  };
  auto solve = [&]() {
    long long X = -1, Y = -1;
    for (long long x = 0; x <= 2e9; x += 5e8) {
      if (X != -1) {
        break;
      }
      for (long long y = 0; y <= 2e9; y += 5e8) {
        string res = ask(x, y);
        if (res == "HIT") {
          X = x;
          Y = y;
          break;
        } else if (res == "CENTER") {
          return;
        }
      }
    }
    long long l, r;
    l = X, r = 2e9;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      string res = ask(m, Y);
      if (res == "CENTER") {
        return;
      }
      if (res == "HIT") {
        l = m;
      } else {
        r = m - 1;
      }
    }
    long long R = l;

    l = 0, r = X;
    while (l < r) {
      long long m = (l + r) / 2;
      string res = ask(m, Y);
      if (res == "CENTER") {
        return;
      }
      if (res == "HIT") {
        r = m;
      } else {
        l = m + 1;
      }
    }
    long long L = l;
    long long c_x = (L + R) / 2;
    l = Y, r = 2e9;
    while (l < r) {
      long long m = (l + r + 1) / 2;
      string res = ask(c_x, m);
      if (res == "CENTER") {
        return;
      }
      if (res == "HIT") {
        l = m;
      } else {
        r = m - 1;
      }
    }
    long long U = l;

    l = 0, r = Y;
    while (l < r) {
      long long m = (l + r) / 2;
      string res = ask(c_x, m);
      if (res == "CENTER") {
        return;
      }
      if (res == "HIT") {
        r = m;
      } else {
        l = m + 1;
      }
    }
    long long D = l;

    long long c_y = (U + D) / 2;
    ask(c_x, c_y);
  };
  int T, A, B;
  cin >> T >> A >> B;
  while (T--) {
    solve();
  }
}
