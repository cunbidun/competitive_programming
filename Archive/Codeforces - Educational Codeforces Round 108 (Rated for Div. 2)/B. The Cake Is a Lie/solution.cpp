#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  vector<set<array<int, 2>>> st(10001);
  st[0].insert({1, 1});
  for (int i = 1; i <= 100; i++) {
    for (int j = 1; j <= 100; j++) {
      for (int k = 1; k <= 10000; k++) {
        if (k >= j) {
          if (st[k - j].find({i - 1, j}) != st[k - j].end()) {
            st[k].insert({i, j});
          }
        }
        if (k >= i) {
          if (st[k - i].find({i, j - 1}) != st[k - i].end()) {
            st[k].insert({i, j});
          }
        }
      }
    }
  }
  int t;
  cin >> t;
  while (t--) {
    int n, m, k;
    cin >> n >> m >> k;
    if (st[k].find({n, m}) != st[k].end()) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
