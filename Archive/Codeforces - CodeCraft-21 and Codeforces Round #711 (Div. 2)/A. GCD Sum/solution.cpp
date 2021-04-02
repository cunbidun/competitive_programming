#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = n;; i++) {
      long long s = 0, tmp = i;
      while (tmp) {
        s += tmp % 10;
        tmp /= 10;
      }
      if (__gcd(s, i) > 1) {
        cout << i << '\n';
        break;
      }
    }
  }
}
