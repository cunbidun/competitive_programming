#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q, k;
  cin >> n >> q >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    cout << k + a[r - 1] - a[l - 1] - 2 * (r - l + 1) + 1 << "\n";
  }
}
