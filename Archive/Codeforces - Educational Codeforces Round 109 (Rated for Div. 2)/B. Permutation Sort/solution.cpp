#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] == n && a[n - 1] == 1) {
      cout << 3 << '\n';
      continue;
    }
    if (a[0] != 1 && a[n - 1] != n) {
      cout << 2 << '\n';
      continue;
    }
    cout << 1 - is_sorted(a.begin(), a.end()) << '\n';
  }
}
