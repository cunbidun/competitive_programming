#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << fixed << setprecision(10);
  double w, h, a;
  cin >> w >> h >> a;
  if (a == 90) {
    cout << min(h, w) * min(h, w) << '\n';
    return 0;
  }
  if (w < h) {
    swap(w, h);
  }
  if (a > 90) {
    a = 180 - a;
  }
  a = a / 180 * PI;
  double x = w / 2 - tan(a / 2) * h / 2;
  double y = x * tan(a);
  if (y > h) {
    x = tan(a / 2) * h / 2 + tan(PI / 2 - a / 2) * h / 2;
    cout << 2 * x * h / 2 << '\n';
    return 0;
  }
  double big = x * y / 2;
  x = h / 2 - tan(a / 2) * w / 2;
  y = x * tan(a);
  double small = x * y / 2;
  cout << (2 * w * h - 4 * big - 4 * small) / 2 << '\n';
}
