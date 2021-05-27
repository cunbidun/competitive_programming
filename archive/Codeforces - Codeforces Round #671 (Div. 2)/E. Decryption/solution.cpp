#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> l1, l2;
    for (int i = 2; i * i <= n; i++) {
      if (n % i == 0) {
        if (i != 1) {
          l1.push_back(i);
        }
        if (n / i != i) {
          l2.push_back(n / i);
        }
      }
    }
    int c = 0;
    if (l1.size() > l2.size()) {
      l1.pop_back();
      c = 1;
    }
    for (int i = 1; i < l1.size(); i++) {
      if (__gcd(l1[i], l1[i - 1]) == 1) {
        swap(l1[i], l2[i]);
      }
      if (__gcd(l2[i], l2[i - 1]) == 1) {
        swap(l1[i], l2[i]);
      }
    }
    reverse(l2.begin(), l2.end());
    if (l1.size() > 0) {
      if (__gcd(l1[0], l2[0]) != 1) {
        reverse(l2.begin(), l2.end());
      } else if (__gcd(l1.back(), l2.back()) != 1) {
        reverse(l1.begin(), l1.end());
      }
    }
    if (c) {
      l1.push_back((int)sqrt(n));
    }
    l1.push_back(n);
    for (int i : l2) {
      l1.push_back(i);
    }
    cout << l1[0] << ' ';
    int ans = 0;
    for (int i = 1; i < l1.size(); i++) {
      if (__gcd(l1[i], l1[i - 1]) == 1) {
        ans++;
      }
      cout << l1[i] << ' ';
    }
    cout << '\n';
    ans += (__gcd(l1.front(), l1.back()) == 1);
    cout << ans << '\n';
  }
}
