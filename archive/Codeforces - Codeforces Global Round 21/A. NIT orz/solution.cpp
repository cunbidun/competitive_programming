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
  while (T--) {
    int N, Z;
    cin >> N >> Z;
    int ans = 0;
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      ans = max(ans, x | Z);
      ans = max(ans, x);
    }
    cout << ans << '\n';
  }
}
