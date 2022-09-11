/**
 *    author:  tourist
 *    created: 10.09.2022 20:01:24
 **/

#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

template <typename T> vector<int> z_function(int n, const T &s) {
  vector<int> z(n, n);
  int l = 0, r = 0;
  for (int i = 1; i < n; i++) {
    z[i] = (i > r ? 0 : min(r - i + 1, z[i - l]));
    while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
      z[i]++;
    }
    if (i + z[i] - 1 > r) {
      l = i;
      r = i + z[i] - 1;
    }
  }
  return z;
}

template <typename T> vector<int> z_function(const T &s) { return z_function((int)s.size(), s); }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int tt;
  cin >> tt;
  for (int qq = 1; qq <= tt; qq++) {
    cout << "Case #" << qq << ": ";
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    vector<int> c(3 * n);
    for (int i = 0; i < n; i++) {
      c[i] = b[i];
      c[i + n] = a[i];
      c[i + n + n] = a[i];
    }
    auto z = z_function(c);
    bool win = false;
    for (int i = n; i < 2 * n; i++) {
      if (z[i] >= n) {
        if (k == 0) {
          if (i == n) {
            win = true;
          }
          continue;
        }
        if (k == 1) {
          if (i != n) {
            win = true;
          }
          continue;
        }
        if (n == 2) {
          if (k % 2 == i % 2) {
            win = true;
          }
          continue;
        }
        win = true;
      }
    }
    cout << (win ? "YES" : "NO") << '\n';
  }
  return 0;
}
