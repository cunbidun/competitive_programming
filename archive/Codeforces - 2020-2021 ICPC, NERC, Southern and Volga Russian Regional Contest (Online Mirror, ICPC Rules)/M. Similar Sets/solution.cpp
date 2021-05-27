#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    vector<int> l;
    map<int, int> mp;
    auto compress = [&] {
      sort(l.begin(), l.end());
      l.resize(distance(l.begin(), unique(l.begin(), l.end())));
      for (int i : l) {
        mp[i] = mp.size() + 1;
      }
    };

    int n;
    cin >> n;
    int m = 0;
    vector<vector<int>> a;
    for (int i = 0; i < n; i++) {
      vector<int> tmp;
      int k;
      cin >> k;
      while (k--) {
        int x;
        cin >> x;
        l.push_back(x);
        tmp.push_back(x);
        m++;
      }
      a.push_back(tmp);
    }
    compress();

    for (auto &v : a) {
      for (int i = 0; i < (int)v.size(); i++) {
        v[i] = mp[v[i]];
      }
      sort(v.begin(), v.end());
    }
    vector<int> check(m + 5, 0);
    int D = 200;
    vector<vector<array<int, 2>>> p(m + 5);
    auto solve = [&]() {
      for (int cur = 0; cur < (int)a.size(); cur++) {
        auto v = a[cur];
        if ((int)v.size() > D) {
          for (int i : v) {
            check[i] = 1;
          }
          for (int i = 0; i < (int)a.size(); i++) {
            if (i != cur) {
              int cnt = 0;
              for (int j : a[i]) {
                cnt += check[j];
                if (cnt == 2) {
                  cout << cur + 1 << ' ' << i + 1 << '\n';
                  return;
                }
              }
            }
          }
          for (int i : v) {
            check[i] = 0;
          }
        } else {
          for (int i = 0; i < (int)v.size() - 1; i++) {
            for (int j = i + 1; j < (int)v.size(); j++) {
              p[v[i]].push_back({v[j], cur});
            }
          }
        }
      }
      vector<vector<int>> store(m + 5);
      for (int i = 1; i <= m; i++) {
        for (auto [f, s] : p[i]) {
          store[f].push_back(s);
        }
        for (auto [f, s] : p[i]) {
          if (store[f].size() >= 2) {
            cout << store[f][0] + 1 << ' ' << store[f][1] + 1 << '\n';
            return;
          }
          store[f].clear();
        }
      }
      cout << -1 << '\n';
    };
    solve();
  }
}
