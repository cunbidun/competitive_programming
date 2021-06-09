#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    vector<array<int, 2>> a(4);
    for (int i = 0; i < 4; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end());
    if ((a[2][1] < 2 && a[3][1] < 2) || (a[2][1] >= 2 && a[3][1] >= 2)) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
    }
  }
}
