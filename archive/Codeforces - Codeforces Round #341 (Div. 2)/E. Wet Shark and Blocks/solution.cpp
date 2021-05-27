#include <bits/stdc++.h>

#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> ii;

struct mod_int {
  int MOD;

  mod_int(int MOD) {
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

  int pow(int x, ll p) {
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

template <class T>
class Matrix {
public:
  vector<vector<T>> a;
  int r, c;

  void init(int r, int c) {
    this->r = r;
    this->c = c;
    a.resize(r);
    for (int i = 0; i < r; i++) {
      a[i].resize(c);
    }
  }

  Matrix operator*(const Matrix &o) const {
    Matrix res;
    res.init(r, o.c);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < o.c; j++)
        for (int k = 0; k < c; k++) {
          res.a[i][j] = op.add(res.a[i][j], op.mul(a[i][k], o.a[k][j]));
        }
    }
    return res;
  }

  Matrix power(int p) const {
    if (p == 0) {
      Matrix res;
      res.init(r, r);
      for (int i = 0; i < r; i++) {
        res.a[i][i] = 1;
      }
      return res;
    }
    if (p == 1) {
      Matrix res(*this);
      return res;
    }
    Matrix tmp = power(p / 2);
    if (p % 2 == 0) {
      return tmp * tmp;
    }
    return *this * tmp * tmp;
  }

  vector<T> &operator[](int i) {
    return a[i];
  }

  friend std::ostream &operator<<(std::ostream &stream, const Matrix &matrix) {
    for (int i = 0; i < matrix.r; i++) {
      for (int j = 0; j < matrix.c; j++) {
        stream << matrix.a[i][j] << " ";
      }
      stream << endl;
    }
    return stream;
  }
};

int n, b, k, x, cnt[10];
Matrix<int> base;
Matrix<int> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> b >> k >> x;
  for (int i = 1; i <= n; i++) {
    int num;
    cin >> num;
    cnt[num]++;
  }

  base.init(x, x);
  v.init(x, 1);
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < x; j++) {
      for (int l = 1; l <= 9; l++) {
        if ((i * 10 + l) % x == j) {
          base[j][i] += cnt[l];
        }
      }
    }
  }
  v[0][0] = 1;
  // cout << base << "\n";
  base = base.power(b);
  // cout << v << "\n";
  v = base * v;
  cout << v[k][0] << "\n";
}
