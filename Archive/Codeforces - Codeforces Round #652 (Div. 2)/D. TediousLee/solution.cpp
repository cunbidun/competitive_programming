#include <bits/stdc++.h>

using namespace std;

int MOD = 1e9 + 7;
const int N = 2e6 + 1;

int f[N];

int main() {
  f[1] = 0;
  f[2] = 0;
  for (int i = 3; i <= N - 1; i++) {
    f[i] = ((2 * f[i - 2]) % MOD + f[i - 1] + (i % 3 == 0)) % MOD;
  }
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    cout << (1ll * f[n] * 4) % MOD << "\n";
  }
}