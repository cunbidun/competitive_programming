#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >>
        n >> k;
    vector<int> a;
    for (int i = 1; i <= n; i++) {
      a.push_back(i);
    }
    int cur = n - 1;
    while (k) {
      if (cur > 1) {
        swap(a[cur], a[cur - 1]);
        cur -= 2;
        k--;
      } else {
        break;
      }
    }
    if (k != 0) {
      cout << -1 << '\n';
    } else {
      for (int i : a) {
        cout << i << ' ';
      }
      cout << '\n';
    }
  }
}
