#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n + 1), pos(n + 1), used(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      pos[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) {
      for (int j = pos[i]; j <= n; j++) {
        if (used[a[j]]) {
          break;
        }
        used[a[j]] = 1;
        cout << a[j] << ' ';
      }
    }
    cout << "\n";
  }
}
