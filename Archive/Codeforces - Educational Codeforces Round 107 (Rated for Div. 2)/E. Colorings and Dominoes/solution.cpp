#include <bits/stdc++.h>

using namespace std;

struct modInt {
  int MOD;

  modInt(int MOD) {
    this->MOD = MOD;
  }

  int add(int x, int y) {
    return ((x + y) >= MOD ? x + y - MOD : x + y);
  }

  int sub(int x, int y) {
    return ((x - y) < 0 ? x - y + MOD : x - y);
  }

  int mul(int x, int y) {
    return (int)((1LL * x * y) % MOD);
  }

  int pow(int x, long long p) {
    if (p == 0) {
      return 1;
    }
    int t = pow(x, p / 2);
    if ((p & 1) == 1) {
      return mul(mul(t, t), x);
    }
    return mul(t, t);
  }

  int inv(int x) {
    return pow(x, MOD - 2);
  }

  int div(int x, int y) {
    return mul(x, inv(y));
  }
} op(998244353);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  vector<int> p(3e5 + 5);
  vector<int> len(3e5 + 5);
  p[0] = 1;
  for (int i = 1; i <= 300000; i++) {
    p[i] = op.mul(p[i - 1], 2);
  }

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'o') {
        cnt++;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'o') {
        int k = j;
        for (; k < m; k++) {
          if (a[i][k] != 'o') {
            break;
          }
        }
        int d = k - j;
        for (int l = 1; l < d; l++) {
          int pos = (d - l - 2 + 1);
          if (l < d - 1) {
            len[l] = op.add(len[l], op.mul(pos, p[cnt - l - 2]));
          }
          len[l] = op.add(len[l], op.mul(2, p[cnt - l - 1]));
        }
        len[d] = op.add(len[d], p[cnt - d]);
        j = k;
      }
    }
  }

  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (a[j][i] == 'o') {
        int k = j;
        for (; k < n; k++) {
          if (a[k][i] != 'o') {
            break;
          }
        }
        int d = k - j;
        for (int l = 1; l < d; l++) {
          int pos = (d - l - 2 + 1);
          if (l < d - 1) {
            len[l] = op.add(len[l], op.mul(pos, p[cnt - l - 2]));
          }
          len[l] = op.add(len[l], op.mul(2, p[cnt - l - 1]));
        }
        len[d] = op.add(len[d], p[cnt - d]);
        j = k;
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= 300000; i++) {
    ans = op.add(ans, op.mul(len[i], i / 2));
  }
  cout << ans << '\n';
}
