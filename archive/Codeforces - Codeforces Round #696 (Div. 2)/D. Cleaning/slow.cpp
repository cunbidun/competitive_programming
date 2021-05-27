#include <bits/stdc++.h>

using namespace std;

int n, a[100], b[100];

int main() {
  cin >> n >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int f = 0;
  int cur = a[1];
  for (int j = 2; j <= n; j++) {
    cur = a[j] - cur;
    if (cur < 0) {
      f = 1;
      break;
    }
  }
  if (!f && cur == 0) {
    cout << "YES\n";
    return 0;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= n; j++) {
      b[j] = a[j];
    }
    swap(b[i], b[i + 1]);
    int cur = b[1];
    f = 0;
    for (int j = 2; j <= n; j++) {
      cur = b[j] - cur;
      if (cur < 0) {
        f = 1;
        break;
      }
    }
    if (!f && cur == 0) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
}
