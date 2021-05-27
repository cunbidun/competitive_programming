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

  int inv(int x) {
    return pow(x, MOD - 2);
  }

  int div(int x, int y) {
    return mul(x, inv(y));
  }
} op(1e9 + 7);

class BlackBoxDiv2 {
public:
  int count(string front, string side) {
    vector<vector<int>> C(55, vector<int>(55));
    C[1][0] = C[1][1] = 1;
    for (int i = 2; i <= 50; i++) {
      C[i][0] = 1;
      for (int j = 1; j <= i; j++) {
        C[i][j] = op.add(C[i - 1][j - 1], C[i - 1][j]);
      }
    }
    int n = front.size();
    int m = side.size();
    int cntf = 0, cnts = 0;
    for (int i = 0; i < (int)front.size(); i++) {
      if (front[i] == '.') {
        cntf++;
      }
    }
    for (int i = 0; i < (int)side.size(); i++) {
      if (side[i] == '.') {
        cnts++;
      }
    }
    n -= cntf;
    m -= cnts;
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    if ((m == 0 && n != 0) || (n == 0 && m != 0)) {
      return 0;
    }
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
      f[i][1] = 1;
    }
    for (int i = 1; i <= m; i++) {
      f[1][i] = 1;
    }
    for (int i = 2; i <= n; i++) {
      for (int j = 2; j <= m; j++) {
        for (int k = 0; k < i; k++) {
          for (int l = 0; l < j; l++) {
            int num = op.mul(C[i - 1][k], C[j - 1][l]);
            int free = op.pow(2, (i - 1 - k) + (j - 1 - l));
            int pre = f[i - 1 - k][j - 1 - l];
            int add = op.mul(op.mul(num, free), pre);
            f[i][j] = op.add(f[i][j], add);

            int fk = op.pow(2, i - 1 - k);
            int fl = op.pow(2, j - 1 - l);
            if (k == 0) {
              fk = op.sub(fk, 1);
            }
            if (l == 0) {
              fl = op.sub(fl, 1);
            }
            free = op.mul(fk, fl);
            pre = f[i - 1 - k][j - 1 - l];
            add = op.mul(op.mul(num, free), pre);
            f[i][j] = op.add(f[i][j], add);
          }
        }
      }
    }
    return f[n][m];
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  BlackBoxDiv2 m;
  m.count("BB", "BB");
  m.count("BB", "BBB");
  m.count("...BB.B....", "B.B.B.B.B");
}
