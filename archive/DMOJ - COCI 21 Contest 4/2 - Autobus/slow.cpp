#include <bits/stdc++.h>

using namespace std;

int INF = 1e9;

template <class T> class Matrix {
public:
  vector<vector<T>> a;
  int r, c;

  void init(int _r, int _c, int value = 0) {
    this->r = _r;
    this->c = _c;
    a.resize(_r);
    for (int i = 0; i < _r; i++) {
      a[i].assign(_c, value);
    }
  }

  Matrix operator*(const Matrix &o) const {
    Matrix res;
    res.init(r, o.c, INF);
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < o.c; j++)
        for (int k = 0; k < c; k++) {
          res.a[i][j] = min(res.a[i][j], a[i][k] + o.a[k][j]);
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

  vector<T> &operator[](int i) { return a[i]; }

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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M;
  cin >> N >> M;
  vector<vector<int>> path(N + 1, vector<int>(N + 1, INF));
  Matrix<int> m;
  m.init(N + 1, N + 1, INF);
  for (int i = 1; i <= N; i++) {
    m[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    m[a][b] = min(m[a][b], t);
  }
  int K, Q;
  cin >> K >> Q;
  m = m.power(min(N, K));
  while (Q--) {
    int u, v;
    cin >> u >> v;
    if (m[u][v] == INF) {
      cout << -1 << '\n';
    } else {
      cout << m[u][v] << '\n';
    }
  }
}
