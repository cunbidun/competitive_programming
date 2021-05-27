#include <bits/stdc++.h>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int cur = 0;
    vector<int> ans;
    vector<int> p;
    for (int i = 0; i < n; i++) {
      p.push_back(i);
    }
    while (p.size() > 1) {
      int ok = ((__gcd(a[p[p.size() - 1]], a[p[0]])) != 1);
      for (int i = 1; i < p.size(); i++) {
        ok &= ((__gcd(a[p[i]], a[p[i - 1]])) != 1);
      }
      if (ok) {
        break;
      }
      if (cur != p.size() - 1) {
        if (__gcd(a[p[cur]], a[p[cur + 1]]) == 1) {
          ans.push_back(p[cur + 1]);
          p.erase(p.begin() + cur + 1);
        }
        cur++;
        if (cur == p.size()) {
          cur = 0;
        }
      } else {
        if (__gcd(a[p[cur]], a[p[0]]) == 1) {
          ans.push_back(p[0]);
          p.erase(p.begin());
        }
        cur = 0;
      }
    }
    if (p.size() == 1) {
      if (a[p[0]] == 1) {
        ans.push_back(p[0]);
      }
    }
    cout << ans.size() << ' ';
    for (int i : ans) {
      cout << i + 1 << ' ';
    }
    cout << '\n';
  }
}
