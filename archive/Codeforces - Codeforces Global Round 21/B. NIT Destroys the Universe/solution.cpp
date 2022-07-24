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
    int N;
    cin >> N;
    vector<int> a(N + 1);
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
      cin >> a[i];
      if (a[i] == 0) {
        cnt++;
      }
    }
    if (cnt == N) {
      cout << 0 << '\n';
    } else {
      int l = 0, r = 0;
      for (int i = 1; i <= N; i++) {
        if (a[i] != 0) {
          l = i;
          break;
        }
      }
      for (int i = N; i >= 1; i--) {
        if (a[i] != 0) {
          r = i;
          break;
        }
      }
      int f = 0;
      for (int i = l; i <= r; i++) {
        if (a[i] == 0) {
          f = 1;
        }
      }
      cout << 1 + f << '\n';
    }
  }
}
