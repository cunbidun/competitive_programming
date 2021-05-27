#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  set<int> s;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    s.insert(a[i]);
  }
  sort(a.begin(), a.end());
  multiset<int> d;

  auto get_mn = [&d]() -> int {
    return ((d.empty()) ? 0 : *d.rbegin());
  };

  auto del = [&d](int x) {
    auto it = d.find(x);
    d.erase(it);
  };

  auto cal = [&]() -> int {
    if (s.size() == 0) {
      return 0;
    }
    return *s.rbegin() - *s.begin() - get_mn();
  };

  for (int i = 1; i < n; i++) {
    d.insert(a[i] - a[i - 1]);
  }
  cout << cal() << '\n';
  while (q--) {
    int t, x;
    cin >> t >> x;
    if (t == 0) {
      if (s.size() != 1) {
        auto it = s.upper_bound(x);
        if (it == s.end()) {
          it--;
          int h = *it;
          it--;
          del(h - (*it));
        } else {
          int h = *it;
          it--;
          if (it == s.begin()) {
            del(h - (*it));
          } else {
            del(h - (*it));
            int c = *it;
            it--;
            del(c - (*it));
            d.insert(h - (*it));
          }
        }
      }
      s.erase(x);
    } else {
      if (s.size() != 0) {
        auto it = s.upper_bound(x);
        if (it == s.end()) {
          it--;
          d.insert(x - (*it));
        } else if (it == s.begin()) {
          d.insert((*it) - x);
        } else {
          int h = *it;
          it--;
          del(h - *it);
          d.insert(h - x);
          d.insert(x - *it);
        }
      }
      s.insert(x);
    }
    cout << cal() << '\n';
  }
}
