#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if ((i - j) % 2 == 0) {
        cout << 720720 << " ";
      } else {
        cout << 720720 - x * x * x * x << " ";
      }
    }
    cout << "\n";
  }
}
