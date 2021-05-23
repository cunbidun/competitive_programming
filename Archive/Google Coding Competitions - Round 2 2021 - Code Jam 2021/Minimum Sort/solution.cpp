#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T, N;
  cin >> T >> N;
  while (T--) {
    int r = 0;
    for (int i = 1; i < 100; i++) {
      cout << "M " << i << ' ' << 100 << endl;
      cin >> r;
      if (r != i) {
        cout << "S " << i << ' ' << r << endl;
        cin >> r;
      }
    }
    cout << "D" << endl;
    cin >> r;
  }
}
