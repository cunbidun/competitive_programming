#include <bits/stdc++.h>

using namespace std;

struct modInt {
  int MOD;

  modInt(int MOD) {
    this->MOD = MOD;
  }

  int mul(int x, int y) {
    return (int)((1LL * x * y) % MOD);
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;
  modInt op(n);
  int cnt = 0;
  int m = 1;
  for (int i = 1; i < n; i++) {
    if (__gcd(i, n) == 1) {
      cnt++;
      m = op.mul(m, i);
    }
  }
  if (m != 1) {
    cnt--;
  }
  cout << cnt << '\n';
  cout << 1 << ' ';
  for (int i = 2; i < n; i++) {
    if (i != m && __gcd(i, n) == 1) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}
