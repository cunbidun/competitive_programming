#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  int mx = 0, mn = 1e9;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mx = max(mx, x);
  }
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    mn = min(mn, x);
  }
  cout << max(0, mn - mx + 1) << '\n';
}
