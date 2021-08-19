#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int Add(int x, int y) {
  int z = x + y;
  if (z >= mod)
    z -= mod;
  return z;
}

int Sub(int x, int y) {
  int z = x - y;
  if (z < 0)
    z += mod;
  return z;
}

int Mul(int x, int y) {
  return (x * 1ll * y) % mod;
}

int powlog(int base, int power) {
  if (power == 0)
    return 1;
  int x = powlog(base, power / 2);
  x = Mul(x, x);
  if (power & 1)
    x = Mul(x, base);
  return x;
}

int modinv(int x) {
  return powlog(x, mod - 2);
}

int Div(int x, int y) {
  return Mul(x, modinv(y));
}

const int MAX = 1e5 + 10;

int L[MAX], R[MAX];
int dp[2][MAX], ways[MAX];

int n, m;

int calc(int x) {
  for (int j = 0; j <= m; j += x)
    dp[0][j] = 0;
  dp[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    int now = (i & 1);
    int prv = !now;
    int sum = 0, l = 0, r = 0;
    if (R[i] < x)
      return 0;
    for (int j = 0; j <= m; j += x) {
      while (j - L[i] >= r)
        sum = Add(sum, dp[prv][r]), r += x;
      while (j - R[i] > l)
        sum = Sub(sum, dp[prv][l]), l += x;
      dp[now][j] = sum;
    }
  }
  int cnt = 0;
  for (int j = x; j <= m; j += x)
    cnt = Add(cnt, dp[n & 1][j]);
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 1; i <= n; ++i)
    cin >> L[i] >> R[i];
  for (int i = m; i >= 1; --i) {
    ways[i] = calc(i);
    for (int j = i + i; j <= m; j += i)
      ways[i] = Sub(ways[i], ways[j]);
  }
  return cout << ways[1] << "\n", 0;
}
