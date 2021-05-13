#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long a, b;
    cin >> a >> b;
    if (b == 1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << a << ' ' << a * b * 17 - a << ' ' << a * b * 17 << '\n';
    }
  }
}
