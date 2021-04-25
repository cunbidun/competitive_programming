#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  string a[2];
  a[0] = 'a';
  a[1] = 'a';
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[0] += c;
  }
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    a[1] += c;
  }
  int q;
  cin >> q;
  int order = 0;
  while (q--) {
    int t, a0, b0;
    cin >> t >> a0 >> b0;
    if (t == 2) {
      order = 1 - order;
    } else {
      if (a0 <= n && b0 <= n) {
        swap(a[order][a0], a[order][b0]);
      }
      if (a0 <= n && b0 > n) {
        swap(a[order][a0], a[1 - order][b0 - n]);
      }
      if (a0 > n && b0 <= n) {
        swap(a[1 - order][a0 - n], a[order][b0]);
      }
      if (a0 > n && b0 > n) {
        swap(a[1 - order][a0 - n], a[1 - order][b0 - n]);
      }
    }
  }
  cout << a[order].substr(1) << a[1 - order].substr(1) << '\n';
}
