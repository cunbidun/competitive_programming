/**
 *  author: cunbidun
 *  created: Wednesday, 2023-01-04 20:23:16 CST
 **/
#include <array>
#include <assert.h>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

struct mod_int {
  int MOD;
  mod_int(int MOD) { this->MOD = MOD; }
  int add(int x, int y) { return ((x + y) >= MOD ? x + y - MOD : x + y); }
  int sub(int x, int y) { return ((x - y) < 0 ? x - y + MOD : x - y); }
  int mul(int x, int y) { return (int)((1LL * x * y) % MOD); }
  int pow(int x, int p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }
  int inv(int x) { return pow(x, MOD - 2); }
  int div(int x, int y) { return mul(x, inv(y)); }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long N, M, K;
  cin >> N >> M >> K;

  const int MOD = 1e9 + 7;
  long long sum = 0;
  long long m_sq = (M * M) % MOD;
  long long n_sq = (N * N) % MOD;
  for (long long i = N - 1; i >= 1; i--) {
    sum += m_sq * (i * (N - i)) % MOD;
    sum %= MOD;
  }
  for (long long i = M - 1; i >= 1; i--) {
    sum += n_sq * (i * (M - i)) % MOD;
    sum %= MOD;
  }

  auto compute = [](long long n, long long k) -> long long {
    if (n >= MOD) {
      return 0;
    }
    if (k > n - k) {
      k = n - k;
    }
    int res = 1;
    int div = 1;
    for (int i = n - k + 1; i <= n; i++) {
      res = (1LL * res * i) % MOD;
    }
    for (int i = 1; i <= k; i++) {
      div = (1LL * div * i) % MOD;
    }
    return mod_int(MOD).div(res, div);
  };

  cout << (sum * compute(N * M - 2, K - 2)) % MOD << '\n';
}
