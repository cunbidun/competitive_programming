#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int n;
    long long k;
    cin >> n >> k;
    vector<long long> a(n);
    long long gcd = 0;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
      gcd = __gcd(a[i] - a[i - 1], gcd);
    }
    if ((k - a[0]) % gcd == 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
