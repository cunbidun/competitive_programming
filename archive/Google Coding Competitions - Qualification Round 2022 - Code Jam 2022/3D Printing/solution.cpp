#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Case #" << tt << ": ";
    vector<int> a(4, 100000000);
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 4; j++) {
        int x;
        cin >> x;
        a[j] = min(a[j], x);
      }
    }
    int sum = 0;
    for (int i = 0; i < 4; i++) {
      if (a[i] == 0) {
        sum = -1e9;
      }
      sum += a[i];
    }
    if (sum < 1e6) {
      cout << "IMPOSSIBLE\n";
    } else {
      sum = 0;
      for (int i = 0; i < 4; i++) {
        int cur = min((int)1e6 - (4 - i - 1) - sum, a[i]);
        cout << cur << ' ';
        sum += cur;
      }
      cout << '\n';
    }
  }
}
