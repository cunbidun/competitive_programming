#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int a, b;
  cin >> a >> b;
  int s = 0;
  for (int i = 1; i < b; i++) {
    s = (s + i) % MOD;
  }
  int ans = 0;
  for (int i = 1; i <= a; i++) {
    ans = (ans + (1LL * ((1LL * i * b) % MOD + 1) * s) % MOD) % MOD;
  }
  cout << ans << "\n";
}
