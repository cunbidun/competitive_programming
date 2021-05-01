#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int r, b, d;
    cin >> r >> b >> d;
    int x = max(r, b) - min(r, b);
    if ((x + min(r, b) - 1) / min(r, b) > d) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
