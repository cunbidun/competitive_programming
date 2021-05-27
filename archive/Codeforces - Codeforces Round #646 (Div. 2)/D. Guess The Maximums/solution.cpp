#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(n);
    for (int i = 1; i <= k; i++) {
      int c;
      cin >> c;
      while (c--) {
        int x;
        cin >> x;
        v[i - 1].push_back(x);
      }
    }

    cout << "? ";
    cout << n << ' ';
    for (int i = 1; i <= n; i++) {
      cout << i << ' ';
    }
    cout << endl;
    int mx;
    cin >> mx;
    int l = 1, r = n;
    while (l < r) {
      int m = (l + r) / 2;
      cout << "? ";
      cout << m - l + 1 << ' ';
      for (int i = l; i <= m; i++) {
        cout << i << ' ';
      }
      cout << endl;
      int res;
      cin >> res;
      if (res == mx) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    vector<int> ans(k);
    int p = -1;
    for (int i = 0; i < k; i++) {
      int f = 0;
      for (int i : v[i]) {
        if (i == l) {
          f = 1;
          break;
        }
      }
      if (!f) {
        ans[i] = mx;
      } else {
        p = i;
      }
    }
    if (p != -1) {
      set<int> s;
      for (int i : v[p]) {
        s.insert(i);
      }
      cout << "? ";
      cout << n - (int)s.size() << ' ';
      for (int i = 1; i <= n; i++) {
        if (s.find(i) == s.end()) {
          cout << i << ' ';
        }
      }
      cout << endl;
      int res;
      cin >> res;
      ans[p] = res;
    }
    cout << "! ";
    for (int i : ans) {
      cout << i << ' ';
    }
    cout << endl;
    string verdict;
    cin >> verdict;
    assert(verdict == "Correct");
  }
}
