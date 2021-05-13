#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, m, x;
    cin >> n >> m >> x;
    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0];
      a[i][1] = i;
    }
    sort(a.begin(), a.end());
    vector<array<int, 2>> b(m);
    for (int i = 0; i < m; i++) {
      b[i][1] = i;
    }
    int cur = n - 1;
    vector<int> ans(n, -1);
    while (cur >= 0) {
      sort(b.begin(), b.end());
      for (int i = 0; i < m; i++) {
        if (cur - i < 0) {
          break;
        }
        ans[a[cur - i][1]] = b[i][1];
        b[i][0] += a[cur - i][0];
      }
      cur -= m;
    }
    cout << "YES\n";
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
