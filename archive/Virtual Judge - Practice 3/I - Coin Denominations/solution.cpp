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
  auto get_pair = [](long long a, long long b, long long c) -> array<long long, 2> {
    long long q = 0, r = 0;
    q += c / MOD;
    r += c % MOD;

    long long closest = a / MOD * MOD;
    q += closest / MOD * b;
    a %= MOD;

    closest = b / MOD * MOD;
    q += closest / MOD * a;
    b %= MOD;

    q += a * b / MOD;
    r += (a * b) % MOD;

    q += r / MOD;
    r %= MOD;
    return {q, r};
  };

  while (M--) {
    long long x;
    cin >> x;
    array<long long, 2> ans = {(long long)4e18, (long long)1e18};
    for (int i = 1; i <= N; i++) {
      long long A = w[i];
      long long B = max((x - 1000000 + a[i] - 1), 0LL) / a[i];
      long long C = f[x - B * a[i]];
      if (C == 1e18) {
        continue;
      }
      auto e = get_pair(A, B, C);
      ans = min(ans, e);
    }
    if (ans[1] == 1e18) {
      cout << -1 << '\n';
    } else {
      cout << ans[1] << '\n';
    }
  }
}
