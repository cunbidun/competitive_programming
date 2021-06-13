#include <bits/stdc++.h>

using namespace std;

struct union_find {
  vector<int> p, child, rank;
  int dsu_size;
  union_find(int _n) {
    dsu_size = _n;
    p.assign(_n, 0);
    rank.assign(_n, 0);
    child.assign(_n, 0);
    for (int i = 0; i < _n; i++) {
      p[i] = i;
      child[i] = 1;
    }
  }
  int find(int i) {
    return (p[i] == i) ? i : (p[i] = find(p[i]));
  }
  bool is_same_set(int x, int y) {
    return find(x) == find(y);
  }
  void merge(int x, int y) {
    if (!is_same_set(x, y)) {
      dsu_size--;
      x = find(x);
      y = find(y);
      if (rank[x] > rank[y]) {
        child[x] += child[y];
        p[y] = x;
      } else {
        p[x] = y;
        child[y] += child[x];
        if (rank[x] == rank[y]) {
          rank[y]++;
        }
      }
    }
  }
  int size(int i) {
    return child[find(i)];
  }
  int num_components() {
    return dsu_size;
  }
};

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
} o(1e9 + 7);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> p1(N + 1), p2(N + 1);
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      p1[x] = i;
    }
    for (int i = 0; i < N; i++) {
      int x;
      cin >> x;
      p2[x] = i;
    }
    union_find dsu(N + 1);
    for (int i = 1; i <= N; i++) {
      dsu.merge(p1[i], p2[i]);
    }
    cout << o.pow(2, dsu.dsu_size - 1) << '\n';
  }
}
