#include <iostream>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  auto ask = [](int c, int d) -> int {
    cout << "? " << c << ' ' << d << endl;
    int r;
    cin >> r;
    assert(r != -2);
    return r;
  };
  auto set = [](int x, int p) { return x | (1 << p); };
  int c = ask(0, 0);
  int a = 0, b = 0;
  for (int i = 29; i >= 0; i--) {
    if (c == 0) {
      int r = ask(a + 0, b + (1 << i));
      if (r > 0) {
        a = set(a, i);
        b = set(b, i);
      }
    } else {
      int r = ask(a + (1 << i), b + (1 << i));
      if (r == -c) {
        if (r == -1) {
          a = set(a, i);
        } else {
          b = set(b, i);
        }
        c = ask(a, b);
      } else {
        if (r > 0) {
          r = ask(a | (1 << i), b);
        } else {
          r = ask(a, b | (1 << i));
        }
        if (r != c) {
          a = set(a, i);
          b = set(b, i);
        }
      }
    }
  }
  cout << "! " << a << ' ' << b << endl;
}
