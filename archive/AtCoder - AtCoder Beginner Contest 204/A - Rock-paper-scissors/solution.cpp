#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int X, Y;
  cin >> X >> Y;
  if (X == Y) {
    cout << X << '\n';
  } else {
    cout << 3 - X - Y << '\n';
  }
}
