#include <bits/stdc++.h>

using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<vector<int>> a(n, vector<int>(n, 0));
  vector<vector<int>> b(n, vector<int>(n, 0));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      a[i][j] = x - '0';
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char x;
      cin >> x;
      b[i][j] = x - '0';
    }
  }
  set<int> r, c;
  for (int i = 0; i < n; i++) {
    if (a[0][i] != b[0][i]) {
      c.insert(i);
    }
  }
  int f = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (c.find(j) != c.end()) {
        a[i][j] ^= 1;
      }
      cnt += (a[i][j] != b[i][j]);
    }
    if (cnt != 0 && cnt != n) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}