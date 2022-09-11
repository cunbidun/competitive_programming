#include <array>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, c, M;
  cin >> N >> c >> M;

  vector<int> a(N + 1), w(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> a[i] >> w[i];
  }

  vector<long long> f(1e6 + 1, 1e18);
  f[0] = 0;
  for (int i = 1; i <= 1000000; i++) {
    for (int j = 1; j <= N; j++) {
      if (i >= a[j]) {
        f[i] = min(f[i], f[i - a[j]] + w[j]);
      }
    }
  }
  while (M--) {
    long long x;
    cin >> x;
    if (f[x] == 1e18) {
      cout << -1 << '\n';
    } else {
      cout << f[x] % MOD << '\n';
    }
  }
}
