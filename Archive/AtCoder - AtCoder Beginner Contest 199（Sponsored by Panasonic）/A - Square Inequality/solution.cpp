#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b, c;
  cin >> a >> b >> c;
  if (a * a + b * b < c * c) {
    cout << "Yes\n";
  } else {
    cout << "No\n";
  }
}
